#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int trap(vector<int>& height){

        int n = height.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);
        int max = 0;

        for(int i=0; i<n; i++){
            if(height[i] > max)
                max = height[i];
            leftMax[i] = max;
        }

        int maxRight = 0;
        for(int i = n-1; i >= 0; i--){
            if(height[i] > maxRight)
                maxRight = height[i];

            rightMax[i] = maxRight;
        }

        int trappedWater = 0;
        for(int i=0; i<n; i++){
            int waterLevel = min(leftMax[i], rightMax[i]);
            if(waterLevel-height[i] > 0)
                trappedWater += waterLevel - height[i];
        }

        return trappedWater;

    }

    int trap2(vector<int>& height){
        int n = height.size();
        if (n == 0) return 0;

        // Create and fill leftMax array
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }

        // Create and fill rightMax array
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = std::max(rightMax[i + 1], height[i]);
        }

        // Calculate the trapped water
        int waterTrapped = 0;
        for (int i = 0; i < n; ++i) {
            waterTrapped += max(std::min(leftMax[i], rightMax[i]) - height[i], 0);
        }

        return waterTrapped;
    }
};

int main(){
    vector<int> height = {4,2,0,3,2,5};
    Solution solution;
    printf("%d",solution.trap(height));
    return 0;
}