#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i > max_reachable)
                return false;

            max_reachable = max(max_reachable, i + nums[i]);
            if(max_reachable >= nums.size()-1)
            return true;
        }
        return false;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    printf("%d",solution.canJump(nums));
}