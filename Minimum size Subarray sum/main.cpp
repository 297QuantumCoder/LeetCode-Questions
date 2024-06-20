#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        int left = 0;
        int minLength = INT_MAX;
        int currentSum = 0;
        
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];
            
            while (currentSum >= target) {
                minLength = min(minLength, right - left + 1);
                currentSum -= nums[left++];
            }
        }
        
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

