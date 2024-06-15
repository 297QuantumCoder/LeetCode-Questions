#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size()-1;
        while(index1 < index2){
            if(numbers[index1] + numbers[index2] > target)
                index2--;
            else if(numbers[index1] + numbers[index2] < target)
                index1++;
            else
                break;
        }
        vector<int> result = {index1+1, index2+1};
        return result;
    }

    vector<int> twoSum2(const std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1}; // Return 1-indexed positions
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        // The problem guarantees that there is exactly one solution, so we should never reach here.
        return {};
    }
};

int main(){
    Solution solution;
    vector<int> numbers = {-1,0};
    int target = -1;
    vector<int> result = solution.twoSum(numbers, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}