# Problem Statement

You are given a string `s` and an array of strings `words`. All the strings in `words` are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of `words` concatenated.

For example, if `words = ["ab", "cd", "ef"]`, then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of `words`.

Return an array of the starting indices of all the concatenated substrings in `s`. You can return the answer in any order.

## Examples

### Example 1:

**Input:** `s = "barfoothefoobarman"`, `words = ["foo", "bar"]`

**Output:** `[0, 9]`

**Explanation:**

The substring starting at 0 is "barfoo". It is the concatenation of ["bar", "foo"] which is a permutation of `words`.

The substring starting at 9 is "foobar". It is the concatenation of ["foo", "bar"] which is a permutation of `words`.

### Example 2:

**Input:** `s = "wordgoodgoodgoodbestword"`, `words = ["word", "good", "best", "word"]`

**Output:** `[]`

**Explanation:**

There is no concatenated substring.

### Example 3:

**Input:** `s = "barfoofoobarthefoobarman"`, `words = ["bar", "foo", "the"]`

**Output:** `[6, 9, 12]`

**Explanation:**

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo", "bar", "the"].

The substring starting at 9 is "barthefoo". It is the concatenation of ["bar", "the", "foo"].

The substring starting at 12 is "thefoobar". It is the concatenation of ["the", "foo", "bar"].

## Constraints:

- `1 <= s.length <= 10^4`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 30`
- `s` and `words[i]` consist of lowercase English letters

# Solution 1:

Let's break down the logic and algorithm to solve the problem of finding all starting indices of concatenated substrings in a given string `s` that consist of all the words in the array `words`.

### Problem Understanding

You are given:

1. A string `s`.
2. An array of strings `words`, where each string in `words` has the same length.

The goal is to find all starting indices in `s` where a concatenation of every word in `words` (in any order) forms a contiguous substring.

### Key Concepts

1. **Word Length**: Since all words have the same length, we denote this length as `wordLength`.
2. **Total Concatenated Length**: The total length of the concatenated substring that includes all words exactly once will be `totalLength = wordLength * number of words`.
3. **Frequency Map**: We need a way to keep track of the number of times each word appears in the array `words`. This is done using a frequency map (hash map).

### Algorithm Steps

1. **Frequency Map Creation**:
    - Create a frequency map that stores the count of each word in `words`.
    - For example, if `words = ["foo", "bar", "foo"]`, the frequency map would be `{"foo": 2, "bar": 1}`.
2. **Sliding Window**:
    - Use a sliding window approach to check substrings of `s` that are of length `totalLength`.
    - For each possible starting index `i` in `s` (from 0 to `s.length - totalLength`):
        - Create a temporary frequency map to count the occurrences of words in the current window.
        - Extract words from the substring starting at index `i` and check if they match the words in the frequency map.
3. **Validation**:
    - For each window starting at index `i`, iterate through the words within that window:
        - Extract a word of length `wordLength` from the current position.
        - Check if this word exists in the original frequency map.
        - If it exists, update the count in the temporary map.
        - If the word is seen more times than it appears in the original map, break the loop.
        - If all words are matched correctly (i.e., the temporary map matches the original frequency map), record the starting index `i`.
4. **Result Compilation**:
    - Collect all valid starting indices and return them as the result.

### Detailed Example

Consider `s = "barfoothefoobarman"` and `words = ["foo", "bar"]`.

1. **Frequency Map**:
    - `{"foo": 1, "bar": 1}`
2. **Sliding Window**:
    - Start from index 0, and check substrings of length `2 * 3 = 6`.
    - Check the substring `"barfoo"` (from index 0 to 5):
        - Extract "bar" → found in map, count is now `{"foo": 0, "bar": 0}`.
        - Extract "foo" → found in map, count is now `{"foo": 0, "bar": 0}`.
        - All words are matched, record index 0.
    - Move to the next possible starting index 1:
        - Check the substring `"arfoot"` (from index 1 to 6):
            - Extract "arf" → not in map, discard.
    - Continue this for all indices up to `s.length - totalLength = 18 - 6 = 12`.

### Result Compilation

- The valid starting indices are recorded during the sliding window checks.
- For the example, the indices are [0, 9].

### Complexity

- **Time Complexity**: `O((s.length - totalLength + 1) * number of words)` in the worst case, due to checking each substring and comparing the words.
- **Space Complexity**: `O(number of words)` for the frequency maps.

This approach efficiently finds all the starting indices of the concatenated substrings by leveraging frequency maps and the sliding window technique.

Below is a C++ implementation to solve the problem of finding all starting indices of concatenated substrings in `s` which are composed of all words in `words`.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (s.empty() || words.empty()) return result;

    int wordLength = words[0].size();
    int wordCount = words.size();
    int totalLength = wordLength * wordCount;

    if (s.size() < totalLength) return result;

    // Frequency map for the words
    unordered_map<string, int> wordFreq;
    for (const string& word : words) {
        wordFreq[word]++;
    }

    // Iterate through the string
    for (int i = 0; i <= s.size() - totalLength; i++) {
        unordered_map<string, int> seenWords;
        int j = 0;
        // Check if we can find all words in the current window
        while (j < wordCount) {
            string word = s.substr(i + j * wordLength, wordLength);
            if (wordFreq.find(word) != wordFreq.end()) {
                seenWords[word]++;
                // If a word is seen more times than it is in words, break
                if (seenWords[word] > wordFreq[word]) break;
            } else {
                break;
            }
            j++;
        }
        // If all words are found
        if (j == wordCount) result.push_back(i);
    }

    return result;
}

int main() {
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> result1 = findSubstring(s1, words1);
    for (int index : result1) {
        cout << index << " ";
    }
    cout << endl;

    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> result2 = findSubstring(s2, words2);
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    string s3 = "barfoofoobarthefoobarman";
    vector<string> words3 = {"bar", "foo", "the"};
    vector<int> result3 = findSubstring(s3, words3);
    for (int index : result3) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

```

### Explanation:

1. **Initialize Variables**:
    - `wordLength` stores the length of each word in `words`.
    - `wordCount` stores the total number of words in `words`.
    - `totalLength` is the length of the concatenated string we need to find.
2. **Frequency Map**:
    - `wordFreq` is an unordered map to store the frequency of each word in `words`.
3. **Iterate Through the String**:
    - For each possible starting index `i` in `s` where a concatenated substring can start:
        - `seenWords` is an unordered map to store the frequency of words we have seen in the current window.
        - Check `wordCount` words starting from `i` to see if they match the required words.
        - If the word is in `wordFreq`, increment its count in `seenWords`. If a word is seen more times than it appears in `words`, break the loop.
        - If all words are found, add the starting index `i` to the result.
4. **Main Function**:
    - Test the function with different input strings and word lists to verify the correctness.

This implementation runs in `O(m * n)` time, where `m` is the length of the string `s` and `n` is the length of `words`, making it efficient for the given constraints.

# Solution 2 :

### Problem Recap

We need to find all starting indices in a string `s` where a substring is formed by concatenating all the words in the array `words`. Each word in `words` has the same length.

### Key Insights

1. **Word Length and Total Length**: All words have the same length `wordLength`. The total length of the concatenated substring is `totalLength = wordLength * number of words`.
2. **Frequency Map**: We use a frequency map to store the count of each word in `words`.
3. **Sliding Window Over Word Boundaries**: We optimize the sliding window approach by only checking starting points that align with word boundaries, which significantly reduces redundant checks.

### Detailed Steps

### Step 1: Frequency Map Creation

- We create a frequency map (hash map) to store how many times each word appears in `words`.

Example:

```cpp
words = ["foo", "bar", "foo"]
wordFreq = {"foo": 2, "bar": 1}

```

### Step 2: Sliding Window Over Word Boundaries

- Instead of checking every single character in `s`, we only check starting positions that align with the beginning of words. We iterate from `0` to `wordLength - 1`.

Example:
If `wordLength` is 3, we will check starting indices `0, 1, 2`.

### Step 3: Check Substrings Using Sliding Window

For each starting point, we:

1. Initialize the left boundary of the window (`left`) and a count of valid words (`count`).
2. Slide a window of size `wordLength` through the string, extracting words from the current position.
3. For each word extracted:
    - **If the word is in the frequency map**:
        - Increment its count in the current window (`seenWords`).
        - Increment the count of valid words (`count`).
        - If the count of the current word exceeds its frequency in the map, move the left boundary to reduce the count.
    - **If the word is not in the frequency map**:
        - Reset the window by clearing `seenWords` and resetting `count` and `left`.
4. If `count` equals the number of words, record the starting index.

### Example Walkthrough

Let's consider `s = "barfoothefoobarman"` and `words = ["foo", "bar"]`.

1. **Frequency Map**:
    
    ```cpp
    wordFreq = {"foo": 1, "bar": 1}
    
    ```
    
2. **Outer Loop**: Iterate `i` from `0` to `2` (since `wordLength = 3`).

### i = 0:

- Initialize `left = 0`, `count = 0`, `seenWords = {}`.
- Extract words starting at `0`, `3`, `6`, `9`, `12`, `15`.
1. `j = 0`: Extract `"bar"`:
    - Found in `wordFreq`, `seenWords = {"bar": 1}`, `count = 1`.
2. `j = 3`: Extract `"foo"`:
    - Found in `wordFreq`, `seenWords = {"bar": 1, "foo": 1}`, `count = 2`.
    - `count == wordCount`, record `left = 0`.
3. `j = 6`: Extract `"the"`:
    - Not in `wordFreq`, reset `left = 9`, `count = 0`, `seenWords = {}`.
4. `j = 9`: Extract `"foo"`:
    - Found in `wordFreq`, `seenWords = {"foo": 1}`, `count = 1`.
5. `j = 12`: Extract `"bar"`:
    - Found in `wordFreq`, `seenWords = {"foo": 1, "bar": 1}`, `count = 2`.
    - `count == wordCount`, record `left = 9`.

### i = 1 and i = 2:

- Similar checks are performed, but no additional valid starting indices are found.

### Result Compilation

- The valid starting indices found are `[0, 9]`.

### Complexity Analysis

- **Time Complexity**: The algorithm processes each character in the string a constant number of times, leading to an overall time complexity of `O(n * wordLength)`, where `n` is the length of `s`.
- **Space Complexity**: The space complexity is `O(number of words)` for the frequency maps.

Optimizing the solution to achieve better time complexity involves leveraging sliding windows and hash maps more effectively. The goal is to avoid re-checking parts of the string unnecessarily. Here's a refined approach:

### Approach

The optimized algorithm uses the following strategy:

1. **Frequency Map**: Create a frequency map for the words in `words`.
2. **Multiple Sliding Windows**: Instead of checking each position in the string `s`, we check starting positions that align with word boundaries more efficiently.
3. **Checking Validity**: Use sliding windows to verify substrings of `s` while keeping track of word counts.

### Detailed Steps

1. **Initialization**:
    - Create a frequency map of the words.
    - Calculate the word length and the total length of the concatenated substring.
2. **Sliding Window Over Word Boundaries**:
    - Loop over possible starting points `i` from `0` to `wordLength - 1` (to cover all possible word alignments).
    - For each starting point, use a sliding window to check substrings.
3. **Sliding Window Checks**:
    - For each starting position, maintain a current count of words found in the current window.
    - Slide the window by moving `wordLength` characters at a time.
    - If a word is found that is not in the frequency map, reset the window.
    - If a word count exceeds the frequency map, adjust the window from the left.
4. **Store Valid Start Indices**:
    - If a valid concatenated substring is found, store the starting index.

Here's the C++ implementation of the optimized solution:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (s.empty() || words.empty()) return result;

    int wordLength = words[0].size();
    int wordCount = words.size();
    int totalLength = wordLength * wordCount;

    if (s.size() < totalLength) return result;

    unordered_map<string, int> wordFreq;
    for (const string& word : words) {
        wordFreq[word]++;
    }

    for (int i = 0; i < wordLength; i++) {
        int left = i, count = 0;
        unordered_map<string, int> seenWords;
        for (int j = i; j <= s.size() - wordLength; j += wordLength) {
            string word = s.substr(j, wordLength);
            if (wordFreq.find(word) != wordFreq.end()) {
                seenWords[word]++;
                count++;

                while (seenWords[word] > wordFreq[word]) {
                    string leftWord = s.substr(left, wordLength);
                    seenWords[leftWord]--;
                    count--;
                    left += wordLength;
                }

                if (count == wordCount) {
                    result.push_back(left);
                }
            } else {
                seenWords.clear();
                count = 0;
                left = j + wordLength;
            }
        }
    }

    return result;
}

int main() {
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> result1 = findSubstring(s1, words1);
    for (int index : result1) {
        cout << index << " ";
    }
    cout << endl;

    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> result2 = findSubstring(s2, words2);
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    string s3 = "barfoofoobarthefoobarman";
    vector<string> words3 = {"bar", "foo", "the"};
    vector<int> result3 = findSubstring(s3, words3);
    for (int index : result3) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

```

### Explanation

1. **Frequency Map**: The frequency map stores the count of each word in `words`.
2. **Sliding Window**:
    - The outer loop iterates over possible starting points `i` from `0` to `wordLength - 1`.
    - `left` is the left boundary of the sliding window, and `count` is the number of valid words found in the current window.
    - The inner loop checks words in the current window starting from `j`.
3. **Validating Substrings**:
    - If the word is in the frequency map, increase its count in `seenWords` and increment `count`.
    - If the count of the current word exceeds its frequency, move the left boundary to reduce the count.
    - If the count of valid words equals the total word count, record the starting index.
4. **Efficiency**:
    - This approach ensures each character in `s` is processed a constant number of times, leading to an overall time complexity of `O(n * wordLength)`, where `n` is the length of `s`. This is more efficient than checking each position individually.

### Conclusion

This approach efficiently finds all starting indices of the concatenated substrings by leveraging the structure of the problem to minimize redundant checks. Using sliding windows aligned with word boundaries ensures we only process necessary substrings, significantly optimizing performance.