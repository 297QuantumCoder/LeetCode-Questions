#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
    int maxArea1(vector<int>& height){
        int n = height.size();
        int maxArea = 0;
        int area = 0;
        int h = 0;
        int width = 0;
        for(int i=0; i < n-1; i++){
            for(int j = i+1; j<n; j++){
                width = j-i;
                h = min(height[i], height[j]);
                area = width * h;
                if(area > maxArea)
                    maxArea = area;
            }
        }
        return maxArea;
    }

    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            maxWater = max(maxWater, width * h);

            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxWater;
    }
};

int main(){
    Solution solution;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << solution.maxArea1(height) << endl;

    cout << solution.maxArea(height) << endl;
    return 0;
}