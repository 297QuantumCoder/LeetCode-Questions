# Set Matrix Zeroes

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it [in place](https://en.wikipedia.org/wiki/In-place_algorithm).

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg">

```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

```

**Example 2:**

<img src = "https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg">

```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

```

**Constraints:**

- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `231 <= matrix[i][j] <= 231 - 1`

**Follow up:**

- A straightforward solution using `O(mn)` space is probably a bad idea.
- A simple improvement uses `O(m + n)` space, but still not the best solution.
- Could you devise a constant space solution?

## Solution :

To solve the problem of setting matrix rows and columns to zero if an element is zero, while doing it in-place with constant space, we can use the following approach:

## Algorithm Explanation

1. **Use the First Row and First Column as Markers**:
    - Instead of using additional arrays to mark rows and columns that need to be zeroed, we use the first row and the first column of the matrix itself as markers.
2. **Determine the Zero Rows and Columns**:
    - First, scan the entire matrix to determine which rows and columns should be zeroed. Use the first row and the first column to store this information. Additionally, use two boolean variables to track whether the first row and the first column themselves need to be zeroed.
3. **Mark the Rows and Columns**:
    - As you scan the matrix, if you find a zero, mark the corresponding positions in the first row and the first column.
4. **Zero Out the Marked Rows and Columns**:
    - Using the markers in the first row and first column, set the appropriate rows and columns to zero.
5. **Handle the First Row and Column**:
    - Finally, based on the boolean variables, set the first row and the first column to zero if needed.

### Example

Given matrix:

```
1 1 1
1 0 1
1 1 1

```

**Step 1: Determine Zero Rows and Columns**

- Scan the matrix and mark the first row and first column.

```
1 0 1
0 0 1
1 1 1

```

**Step 2: Zero Out the Marked Rows and Columns**

- Zero out the rows and columns based on the markers.

```
1 0 1
0 0 0
1 0 1

```

**Step 3: Handle the First Row and Column**

- Check the boolean variables and set the first row and column to zero if needed.

## C++ Code

Here is the C++ code implementing this approach:

```cpp
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    // Determine if first row or first column has any zero
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }

    for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    // Use first row and first column as markers
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero out cells based on markers
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out first row if needed
    if (firstRowHasZero) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }

    // Zero out first column if needed
    if (firstColHasZero) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    setZeroes(matrix1);

    // Output the modified matrix
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    setZeroes(matrix2);

    // Output the modified matrix
    for (const auto& row : matrix2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

```

### Explanation of the Code

- **Boolean Variables**: `firstRowHasZero` and `firstColHasZero` are used to check if the first row or first column need to be zeroed.
- **Marking**: The first pass through the matrix marks the corresponding row and column headers if an element is zero.
- **Zeroing Out**: The second pass through the matrix uses these markers to set the appropriate rows and columns to zero.
- **First Row and Column Handling**: Finally, the first row and column are set to zero based on the initial checks.

This solution ensures the matrix is modified in place with a time complexity of \(O(m \times n)\) and a space complexity of \(O(1)\).