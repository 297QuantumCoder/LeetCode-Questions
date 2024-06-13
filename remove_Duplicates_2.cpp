#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &);


int main(){
    int size,i;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    vector<int> nums(size);

    for(i=0; i<size; i++){
        scanf("%d", &nums[i]);
    }

    int k = removeDuplicates(nums);
    // printf("%d",nums.size());
    printf("%d \n", k);
    printf("The new array is : ");

    for(int i: nums){
        printf("%d ", i);
    }

    return 0;
}

int removeDuplicates(vector<int> &p){
    int k = 1;
    int prev, next;
    int duplicate = 0;
    

    int length = p.size();
    if(length == 1)
        return 1;

    for(int i=1; i < length; i++){
        prev = p[i-1];
        next = i+1;
        if(prev == p[i])
            duplicate ++;
        else
            duplicate = 0;
        
        if(duplicate > 1){
            continue;
        }

        p[k] = p[i];
        k++;     
    }
    return k;
}