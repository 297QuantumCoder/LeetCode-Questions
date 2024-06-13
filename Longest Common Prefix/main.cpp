#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    string longestCommonPrefix(vector<string>& strs){
        int n = strs.size();
        int minLength = INT_MAX;
        string minString;
        for(auto i : strs){
            if(i.length() < minLength){
                minLength = i.length();
                minString = i;
            }
        }
        string prefix = "";
        int countStrings = 0;
        int breakpoint = 0;
        for(int i = 0; i<minString.length(); i++){
            for(auto j : strs){
                if(minString[i] == j[i])
                    countStrings++;
            }
            if(countStrings == n)
                prefix += minString[i];
            else
                break;
            countStrings = 0;
        }
        return prefix;
    }
};

int main(){
    vector<string> strs = {"cir","car"};
    Solution solution;
    // printf("%s", solution.longestCommonPrefix(strs));
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}