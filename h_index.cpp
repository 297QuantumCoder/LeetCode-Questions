#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // WRONG SOLUTION - Does not works for large values of array elements
    // int hIndex(vector<int>& citations) {
    //     int value = 0;
    //     int current_count = 0;
    //     // int max_count = 0;
    //     int h_index = 0;

    //     for(int i = 0; i < citations.size(); i++){
    //         current_count = 0;
    //         for(int j = i; j < citations.size(); j++){
    //             if(citations[i] <= citations[j])
    //                 current_count++;
    //         }
    //         if(current_count >= citations[i]){
    //             value = citations[i];
    //             if(value > h_index)
    //                 h_index = value;
    //         }
    //     }
    //     return h_index;
    // }

    int hIndex2(vector<int>& citations){
        int n = citations.size();
        sort(citations.begin(), citations.end());

        for(int i=0; i<citations.size(); i++)
            if(citations[i] >= n-i)
                return n-i;
        return 0;
    }
};

int main(){
    Solution solution;
    vector<int> citations = {100};
    // printf("%d\n", solution.hIndex(citations));
    printf("%d", solution.hIndex2(citations));
}