#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence1(string s, string t) {
        int i=0;
        int n = t.length();
        int countChar = 0;
        for(char c: s){
            while(i<n){
                if(t[i] == c){
                    countChar++;
                    i++;
                    break;
                }
                i++;
            }
        }

        if(countChar == s.length())
            return true;
        else
            return false;
    }

    bool isSubsequence2(const std::string& s, const std::string& t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
};

int main(){
    Solution solution;
    string s = "";
    string t = " ";
    cout << solution.isSubsequence1(s,t) << endl;
    return 0;
}