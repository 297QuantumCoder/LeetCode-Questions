
### Problem Explanation

Given two strings `s` and `t`, we need to find the minimum window in `s` that contains all characters of `t` (including duplicates). If there is no such window, we return an empty string. 

The solution needs to be efficient, ideally running in O(m + n) time where `m` and `n` are the lengths of `s` and `t`, respectively.

### Approach

1. **Frequency Count**:
   - Use two hash maps: one for the frequency of characters in `t` (`required`), and one for the current window (`windowCounts`).

2. **Sliding Window**:
   - Use two pointers (`left` and `right`) to represent the current window.
   - Expand the window by moving the `right` pointer and include characters in the `windowCounts`.
   - Once the window contains all characters from `t` (checked using the `required` and `windowCounts`), try to contract the window by moving the `left` pointer to find the minimum length window.

3. **Check Validity**:
   - A window is valid if for every character in `t`, the window contains at least as many instances of that character as `t` does.

4. **Update Minimum Window**:
   - Track the smallest window that satisfies the condition.

### C++ Code

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    // Dictionary to store the frequency of characters in t
    unordered_map<char, int> required;
    for (char c : t) {
        required[c]++;
    }

    // Number of unique characters in t that need to be present in the window
    int requiredSize = required.size();
    int formed = 0;  // To keep track of how many unique characters in t are currently in the window

    // Dictionary to store the frequency of characters in the current window
    unordered_map<char, int> windowCounts;

    int left = 0, right = 0;
    int minLength = INT_MAX, minLeft = 0;

    // Start sliding the window
    while (right < s.size()) {
        char c = s[right];
        windowCounts[c]++;

        // If the current character's frequency matches the required frequency
        if (required.find(c) != required.end() && windowCounts[c] == required[c]) {
            formed++;
        }

        // Try to contract the window until it ceases to be 'desirable'
        while (left <= right && formed == requiredSize) {
            c = s[left];
            
            // Update the minimum window size
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                minLeft = left;
            }

            windowCounts[c]--;
            if (required.find(c) != required.end() && windowCounts[c] < required[c]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
}

int main() {
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Result for s1: " << minWindow(s1, t1) << endl;

    string s2 = "a";
    string t2 = "a";
    cout << "Result for s2: " << minWindow(s2, t2) << endl;

    string s3 = "a";
    string t3 = "aa";
    cout << "Result for s3: " << minWindow(s3, t3) << endl;

    return 0;
}
```

### Explanation of the Code

1. **Frequency Maps**:
   - `required`: Stores the frequency of characters in `t`.
   - `windowCounts`: Tracks the frequency of characters in the current window of `s`.

2. **Initialization**:
   - Initialize pointers `left` and `right` to 0.
   - Variables `formed` and `requiredSize` help keep track of how many characters in `t` are satisfied in the current window.

3. **Expand the Window**:
   - Move the `right` pointer to include new characters in the window and update `windowCounts`.

4. **Contract the Window**:
   - Once the window contains all required characters (`formed == requiredSize`), move the `left` pointer to reduce the size of the window while ensuring it still contains all characters of `t`.

5. **Update the Result**:
   - Track the smallest window that meets the criteria and update the result accordingly.

6. **Return Result**:
   - If a valid window is found, return the substring of `s` corresponding to the smallest window. If not, return an empty string.

This algorithm efficiently finds the minimum window containing all characters of `t` in `s` with a time complexity of O(m + n), making it suitable for large input sizes.