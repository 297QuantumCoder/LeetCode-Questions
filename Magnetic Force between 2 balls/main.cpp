#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); // Sort the positions
    
    int low = 1; // Minimum possible distance
    int high = position.back() - position.front(); // Maximum possible distance
    int result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canPlaceBalls(position, m, mid)) {
            result = mid; // mid is a valid answer, try for a larger minimum force
            low = mid + 1;
        } else {
            high = mid - 1; // mid is not valid, try for a smaller minimum force
        }
    }
    
    return result;
    }

    bool canPlaceBalls(vector<int>& position, int m, int minDist) {
        int count = 1; // Place the first ball in the first basket
        int lastPosition = position[0]; // Track the position of the last placed ball

        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPosition >= minDist) {
                count++;
                lastPosition = position[i];
                if (count == m) {
                    return true; // All balls have been placed successfully
                }
            }
        }

        return false; // Not all balls could be placed with the given minDist
    }
};

int main(){
    vector<int> position = {1,2,3,4,7};
    int m = 3;

    Solution solution;
    
    cout << solution.maxDistance(position, m) << endl;
    return 0;
}