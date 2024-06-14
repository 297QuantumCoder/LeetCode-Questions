#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(start <= end){
            if(!((s[start] >= 'a' && s[start] <= 'z' ) || (s[start] >= '0' && s[start] <= '9' ))){
                start++;
                continue;
            }
            
            if(!((s[end] >= 'a' && s[end] <= 'z' ) || (s[end] >= '0' && s[end] <= '9' ))){
                end--;
                continue;
            }

            if(s[start] != s[end]){
                return false;
            }
            start ++;
            end --;
        }
        return true;
    }

    bool isPalindrome2(string s){
        // Remove non-alphanumeric characters and convert to lowercase
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // Check if the processed string is a palindrome
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main(){
    Solution solution;
    string s = "0P";
    cout << solution.isPalindrome(s) << " " << solution.isPalindrome2(s) << endl;

    return 0;
}