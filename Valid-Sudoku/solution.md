# Solution :

To determine if a given `9x9` Sudoku board is valid, we need to validate three conditions:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3x3` sub-boxes must contain the digits `1-9` without repetition.

Here's a detailed breakdown of the algorithm and the logic involved:

### Algorithm and Logic

1. **Initialization:**
    - We use three arrays of sets to track the numbers seen so far for rows, columns, and sub-boxes:
        - `rows[9]`
        - `columns[9]`
        - `boxes[9]`
    - Each set in these arrays will store the digits that have been encountered.
2. **Iterate through each cell in the board:**
    - For each cell at position `(i, j)`, check the value.
    - If the value is a digit from '1' to '9':
        - Determine which sub-box the cell belongs to using the formula: `box_index = (i // 3) * 3 + (j // 3)`.
        - Check if the digit is already present in the corresponding row, column, or sub-box set.
        - If the digit is already present, the board is invalid. Return `false`.
        - If the digit is not present, add it to the corresponding row, column, and sub-box sets.
    - If the value is '.', skip to the next cell.
3. *If all cells are processed without finding any duplicates, the board is valid. Return `true`.

This approach ensures that we only check the necessary cells and keeps track of seen digits efficiently.

### C++ Implementation

Here is the C++ code implementing the above logic:

```cpp
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current = board[i][j];

                if (current == '.') continue;

                // Calculate the box index
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check row, column, and box
                if (rows[i].count(current) || columns[j].count(current) || boxes[boxIndex].count(current)) {
                    return false;
                }

                // Add to row, column, and box sets
                rows[i].insert(current);
                columns[j].insert(current);
                boxes[boxIndex].insert(current);
            }
        }

        return true;
    }
};

```

### Explanation:

1. **Data Structures:**
    - `rows`, `columns`, and `boxes` are vectors of `unordered_set<char>` where each set keeps track of the digits seen in the corresponding row, column, and sub-box, respectively.
2. **Loop through each cell:**
    - For each cell `(i, j)`, if the cell is not empty (i.e., not '.'), we proceed to check if the digit is already present in the corresponding row, column, or sub-box set.
    - Calculate the index of the sub-box using `boxIndex = (i / 3) * 3 + (j / 3)`.
    - If the digit is found in any of the sets, return `false` as it violates Sudoku rules.
    - Otherwise, insert the digit into the appropriate row, column, and sub-box sets.
3. **Final Check:**
    - If all cells are checked without finding any duplicates, return `true`, indicating the board is valid.

This algorithm ensures we efficiently check the Sudoku board's validity by leveraging sets to track the digits seen in rows, columns, and sub-boxes.