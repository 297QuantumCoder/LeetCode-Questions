#include <vector>
#include <algorithm>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        // Initialize two arrays to keep track of candies distribution
        vector<int> leftToRight(n, 1);
        vector<int> rightToLeft(n, 1);
        
        // Left to right pass
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
        }
        
        // Right to left pass
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                rightToLeft[i] = rightToLeft[i + 1] + 1;
            }
        }
        
        // Calculate the total candies needed
        int totalCandies = 0;
        for (int i = 0; i < n; ++i) {
            totalCandies += max(leftToRight[i], rightToLeft[i]);
        }
        
        return totalCandies;
    }
};
