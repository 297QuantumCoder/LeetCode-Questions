#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public : 
        int maxProfit(vector<int>& nums){
            int minVal = nums[0];
            int maxVal = INT_MIN;
            int totalProfit = 0;
            for(int i=0; i<nums.size()-1; i++){
                if(nums[i] < nums[i+1])
                    totalProfit += nums[i+1] - nums[i];
            }

            return totalProfit;
        }

};

int main(){
    Solution solution;
    vector<int> prices = {7,1,5,3,6,4};
    printf("%d",solution.maxProfit(prices));
    return 0;
}