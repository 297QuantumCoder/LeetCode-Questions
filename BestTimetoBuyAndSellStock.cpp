#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int minVal = prices[0], maxVal = INT_MIN;

        for(auto it: prices){
            int cost = it - minVal;
            maxVal = max(maxVal, cost);
            minVal = min(minVal, it);
        }
        return maxVal;
    }
};
