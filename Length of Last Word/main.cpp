#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
    int lengthOfLastWord(string s){
        int len = s.length();
        int countWordLength = 0;
        int breakpoint = 0;
        
        for(int i=len-1; i>=0; i--){
            
            if(s[i] != ' '){
                countWordLength++;
                breakpoint = 1;
            }
                
            else{
                if(breakpoint == 1)
                    break;
                else
                    continue;
            }
        }
        return countWordLength;
    }
};

int main(){
    string s = "Umesh Kumar SInghkk ";
    Solution solution;
    printf("%d", solution.lengthOfLastWord(s));
    return 0;
}