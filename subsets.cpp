#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result = {{}};
       for(int numbers : nums){
            int n = result.size();
            for(int i=0; i < n; i++){
                vector<int> subset = result[i];
                subset.push_back(numbers);
                result.push_back(subset);                
            }
        }
        return result;
    }

    void printSubset(vector<vector<int>> result){
        for(const auto& subset: result){
            printf("[");
            for(int i : subset){
                printf("%d ", i);
            }
            printf("] \n");
        }
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,2,3,4};
    solution.printSubset(solution.subsets(nums));
}