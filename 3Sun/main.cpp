#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Iterate over each element as potential first element of the triplet
        for (int i = 0; i < n - 2; ++i) {
            // Avoid duplicates for the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element of the triplet
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left - 1]);
                    
                    // Skip duplicates for the third element of the triplet
                    do {
                        right--;
                    } while (left < right && nums[right] == nums[right + 1]);
                }
            }
        }
        
        return result;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    
    // Output the result
    cout << "Output:\n";
    for (auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
