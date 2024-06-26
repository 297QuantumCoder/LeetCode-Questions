#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    string minWindow(string s, string t){
        if(s.empty() || t.empty())
            return "";

        unordered_map<char, int> required;
        for(auto i: t)
            required[i]++;

        int requiredSize = required.size();
        int formed = 0;

        int left=0, right=0;
        int minLength = INT_MAX, minLeft = 0;
        unordered_map<char, int> windowCount;

        while(right < s.size()){
            char c = s[right];
            windowCount[c]++;

            if(required.find(c) != required.end() && windowCount[c] == required[c])
                formed++;

            while(left <= right && formed == requiredSize){
                c = s[left];

                if(right-left+1 < minLength){
                    minLength = right - left + 1;
                    minLeft = left;
                }

                windowCount[c]--;

                if(required.find(c) != required.end() && windowCount[c] < required[c])
                    formed--;

                left++;
            }

            right++;
        }

        return (minLength == INT_MAX ? "" : s.substr(minLeft, minLength));
    }
};

int main(){
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Result is " << solution.minWindow(s,t);
    return 0;
}