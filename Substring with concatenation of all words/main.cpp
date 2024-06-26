#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
    public:
    vector<int> findSubstring(string s, vector<string>& words){
        vector<int> result;
        
        if(s.empty() || words.empty())
            return result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        unordered_map<string, int> wordFreq;
        for(auto word: words){
            wordFreq[word]++;
        }

        for(int i=0; i < wordCount; i++){
            int left = i, count=0;
            int len = s.size();
            unordered_map<string, int> seenWord;
            for(int j=i; j < s.size() - wordLength; j += wordLength){
                
                string word = s.substr(j,wordLength);
                
                if(wordFreq.find(word) != wordFreq.end()){
                    seenWord[word]++;
                    count++;

                    while(seenWord[word] > wordFreq[word]){
                        string leftWord = s.substr(left, wordLength);
                        seenWord[leftWord] --;
                        count--;
                        left += wordLength;
                    }

                    if(count == wordCount)
                        result.push_back(left);
                }

                else{
                    seenWord.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words = {"bar", "foo"};
    vector<int> result = solution.findSubstring(s,words);

    for(auto i: result){
        cout << i << " ";
    }
}