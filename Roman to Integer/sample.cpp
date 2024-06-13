#include <iostream>
#include <string>
#include <algorithm>

// Helper function to trim leading and trailing spaces
void trimSpaces(std::string &s) {
    int n = s.length();
    int start = 0, end = n - 1;

    // Remove leading spaces
    while (start < n && s[start] == ' ') {
        start++;
    }

    // Remove trailing spaces
    while (end >= 0 && s[end] == ' ') {
        end--;
    }

    // Reduce multiple spaces to single spaces and remove extra spaces
    int newLength = 0;
    bool spaceFound = false;
    for (int i = start; i <= end; ++i) {
        if (s[i] != ' ') {
            if (spaceFound && newLength > 0) {
                s[newLength++] = ' ';
            }
            s[newLength++] = s[i];
            spaceFound = false;
        } else {
            spaceFound = true;
        }
    }
    s.resize(newLength);
}

// Helper function to reverse a portion of the string
void reverseString(std::string &s, int start, int end) {
    while (start < end) {
        std::swap(s[start++], s[end--]);
    }
}

std::string reverseWords(std::string s) {
    // Step 1: Trim the string to remove leading/trailing spaces and reduce multiple spaces
    trimSpaces(s);

    // Step 2: Reverse the entire string
    int n = s.length();
    reverseString(s, 0, n - 1);

    // Step 3: Reverse each word in the reversed string
    int start = 0;
    for (int end = 0; end < n; ++end) {
        if (s[end] == ' ') {
            reverseString(s, start, end - 1);
            start = end + 1;
        }
    }
    // Reverse the last word
    reverseString(s, start, n - 1);

    return s;
}

int main() {
    std::string s1 = "the sky is blue";
    std::string s2 = "  hello world  ";
    std::string s3 = "a good   example";

    std::cout << "Input: \"" << s1 << "\"" << std::endl;
    std::cout << "Output: \"" << reverseWords(s1) << "\"" << std::endl;

    std::cout << "Input: \"" << s2 << "\"" << std::endl;
    std::cout << "Output: \"" << reverseWords(s2) << "\"" << std::endl;

    std::cout << "Input: \"" << s3 << "\"" << std::endl;
    std::cout << "Output: \"" << reverseWords(s3) << "\"" << std::endl;

    return 0;
}
