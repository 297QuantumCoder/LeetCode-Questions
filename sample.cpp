#include <iostream>
#include <vector>
using namespace std;

void reverse_array (vector<int>& nums, int begin, int end){
        int temp = 0;
        for(int i = begin; i <= (begin+end)/2; i++){
            temp = nums[i];
            nums[i] = nums[end-i];
            nums[end-i] = temp;
        }
}

void printArray(vector<int>& nums){
        for(int element: nums)
            printf("%d ", element);
        cout << endl;
}


int main(){
    vector<int> arr = {1,2,3,4};
    reverse_array(arr, 0, arr.size()-1);
    printArray(arr);
    printf("%d", arr.end());
}