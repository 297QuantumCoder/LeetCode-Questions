# Problem Statement

You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90** degrees (clockwise).

You have to rotate the image [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm), which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg">


```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

```

**Example 2:**

<img src="
https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg">

```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

```

**Constraints:**

- `n == matrix.length == matrix[i].length`
- `1 <= n <= 20`
- `1000 <= matrix[i][j] <= 1000`

# Solution

## Algorithm Explanation

To rotate a matrix by 90 degrees clockwise in place, you can use the following two-step process:

1. **Transpose the Matrix**:
    - Transposing a matrix means converting all rows to columns and columns to rows. In other words, the element at position `(i, j)` in the original matrix will be at position `(j, i)` in the transposed matrix.
    - For an in-place transpose, swap elements `matrix[i][j]` with `matrix[j][i]` for all `i` and `j` where `i < j`.
2. **Reverse each Row**:
    - After transposing the matrix, reverse the elements of each row to achieve the 90 degrees clockwise rotation.

### Detailed Steps

1. **Transpose the Matrix**:
    - Iterate through the upper triangle of the matrix (excluding the diagonal) and swap the elements with their corresponding elements in the lower triangle.
2. **Reverse each Row**:
    - For each row in the matrix, reverse the elements of that row.

### Example

Given matrix:

```
1 2 3
4 5 6
7 8 9

```

**Step 1: Transpose the Matrix**

```
1 4 7
2 5 8
3 6 9

```

**Step 2: Reverse each Row**

```
7 4 1
8 5 2
9 6 3

```

The matrix is now rotated 90 degrees clockwise.

## C++ Code

Here's the C++ implementation of the described algorithm:

```cpp
#include <vector>
#include <algorithm>  // for std::reverse

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate(matrix1);

    // Output the rotated matrix
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    rotate(matrix2);

    // Output the rotated matrix
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

- The function `rotate` takes a reference to a 2D vector `matrix` and performs the in-place rotation.
- The first nested loop transposes the matrix by swapping elements at positions `(i, j)` and `(j, i)` for `i < j`.
- The second loop reverses each row using `std::reverse`.
- In the `main` function, we test the `rotate` function with two example matrices and print the results.

This approach ensures that the matrix is rotated in place with a time complexity of \(O(n^2)\) and space complexity of \(O(1)\), meeting the constraints of the problem.