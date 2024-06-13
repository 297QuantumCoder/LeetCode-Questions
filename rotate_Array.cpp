#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        int next = 0;
        for(int i=0; i < k; i++){
            int temp = nums[0];
            for(int j = length-1; j >= 0; j--){
                next = (j+1)%length;
                nums[next] = nums[j];
                if(next == 1)
                    nums[next] = temp;
            }
        }
    }

    void printArray(vector<int>& nums){
        for(int element: nums)
            printf("%d ", element);
        cout << endl;
    }

    void rotate2(vector<int>& nums, int k){
        
        int length = nums.size();
        k = k % length;
        vector<int> elements(k);
        int next = 0;
        int count = k-1;

        for(int i=0; i < k; i++){
            elements[i] = nums[i];
        }
        for(int j = length-1; j >= 0; j--){
            next = (j+k)%length;
            nums[next] = nums[j];
            if(j<k){
                nums[next] = elements[count];
                count--;
            }
        }
    }

    void rotate3(vector<int>& nums, int k) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(nullptr);

        int n = nums.size();
        k = k % n;

        reverse_array(nums, 0, nums.size()-1);        
        reverse_array(nums, 0, k-1);
        reverse_array(nums, k, nums.size()-1);
    }

    void reverse_array (vector<int>& nums, int begin, int end){
        int temp = 0;
        for(int i = begin; i <= (begin+end)/2; i++){
            temp = nums[i];
            nums[i] = nums[end-i];
            nums[end-i] = temp;
        }
}
};

int main(){
    Solution solution1, solution2;
    vector<int> nums = {1,2,3,4,5};
    vector<int> nums2 = {1,2,3,4,5,6,7,8,9};

    solution1.rotate(nums,3);
    solution1.printArray(nums);
    // solution1.reverse_array(nums, nums.begin(), nums.end()-1);
    
    solution2.rotate3(nums2,3);
    solution2.printArray(nums2);
}