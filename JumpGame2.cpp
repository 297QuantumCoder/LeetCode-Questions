#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps = 0, current_end = 0, farthest = 0;
        
        int n = nums.size();

        for(int i = 0; i<n-1; i++){
        
            farthest = max(farthest, i+nums[i]);
        
            if(current_end == i){
                
                jumps++;
                current_end = farthest;
                
                if(current_end >= n-1)
                    break;
            }
        }
        
        return jumps; 
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    printf("%d",solution.jump(nums));
}