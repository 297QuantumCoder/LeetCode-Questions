#include <iostream>
#include <string>
using namespace std;
class Solution{
    public:
    string reverseWords(string s){
        
        int len  = s.length();
        int i=0;
        string result="";
        
        while(i < len){
            while(s[i] == '*'){
                i++;
            }
            string word = "";
            while(s[i] != '*' && i<len){
                word = word + s[i];
                i++;
            }
           // cout << word;
            result = word +" "+ result;
        }
        result.erase(result.length()-1,1);
        if(result[0]==' ')
            result.erase(0,1);
        return result;
    }

    string reverseWords2(string s){
        
    }
};

int main(){
    Solution solution;
    string s = "*hello*world*";
    cout << s << endl;
    cout << solution.reverseWords(s) << endl;
}