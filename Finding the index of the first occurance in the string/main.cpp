#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int h = haystack.length();

        if(n<=0)
            return 0;
        
        if(h<n)
            return -1;
        else
            for(int i = 0; i < h - n; i++){
                if((haystack.substr(i,n)) == needle)
                    return i;
            }
        return -1; 
    }
};

int main(){
    Solution solution;
    string haystack = "umesh is noob";
    string needle = "is";
    cout << haystack.substr(1,4) << endl;
    cout << solution.strStr(haystack,needle) << endl;
    return 0;
}
