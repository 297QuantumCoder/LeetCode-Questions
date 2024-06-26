#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
    public:
    bool isValidSudoku(vector<vector<char>>& board){
        
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> column(9);
        vector<unordered_set<char>> boxes(9);

        int boxItem = 0;
        for(int i=0; i < 9; i++){
            for(int j=0; j < 9; j++){
                char c = board[i][j];
                
                if(c == '.')
                    continue;

                boxItem = (i/3)*3 + (j/3);

                if(row[i].count(c) || column[j].count(c) || boxes[boxItem].count(c))
                    return false;

                row[i].insert(c);
                column[j].insert(c);
                boxes[boxItem].insert(c);
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << solution.isValidSudoku(board) << endl;
}