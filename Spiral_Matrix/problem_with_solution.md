# Spiral Matrix

Given an `m x n` `matrix`, return *all elements of the* `matrix` *in spiral order*.

**Example 1:**

<https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg>


```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

```

**Example 2:**

<https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg>

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `100 <= matrix[i][j] <= 100`

<br>

# Solution

To return all elements of a given m x n matrix in spiral order, we need to follow a specific traversal pattern. Let's break down the algorithm and then provide the C++ implementation.

## Algorithm Explanation

1. **Define Boundaries:**
    - `top`: initially set to 0, represents the topmost row that hasn't been traversed yet.
    - `bottom`: initially set to `m - 1`, represents the bottommost row that hasn't been traversed yet.
    - `left`: initially set to 0, represents the leftmost column that hasn't been traversed yet.
    - `right`: initially set to `n - 1`, represents the rightmost column that hasn't been traversed yet.
2. **Traverse the Matrix:**
    - Traverse from `left` to `right` along the `top` row, then increment `top` (move down).
    - Traverse from `top` to `bottom` along the `right` column, then decrement `right` (move left).
    - Traverse from `right` to `left` along the `bottom` row, then decrement `bottom` (move up).
    - Traverse from `bottom` to `top` along the `left` column, then increment `left` (move right).
    - Repeat the above steps until the boundaries overlap or cross each other.
3. **End Condition:**
    - The process stops when `top` > `bottom` or `left` > `right`.

By following this pattern, we ensure that we traverse the matrix in a spiral order.

## C++ Implementation

```cpp
#include <vector>
#include <iostream>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;
    if (matrix.empty() || matrix[0].empty()) {
        return result;
    }

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; ++i) {
            result.push_back(matrix[top][i]);
        }
        ++top;  // Move down to the next row

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; ++i) {
            result.push_back(matrix[i][right]);
        }
        --right;  // Move left to the next column

        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            --bottom;  // Move up to the next row
        }

        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            ++left;  // Move right to the next column
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> result1 = spiralOrder(matrix1);

    std::cout << "Spiral order of matrix1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    std::vector<int> result2 = spiralOrder(matrix2);

    std::cout << "Spiral order of matrix2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

```

### Explanation of the Code

1. **Input Handling:** The function checks if the matrix is empty and returns an empty result if true.
2. **Boundary Initialization:** The initial boundaries (`top`, `bottom`, `left`, `right`) are set based on the dimensions of the matrix.
3. **While Loop:** The loop continues as long as the top boundary does not exceed the bottom and the left boundary does not exceed the right.
4. **Traversals:**
    - **Top Row:** Elements are added from left to right, then the top boundary is incremented.
    - **Right Column:** Elements are added from top to bottom, then the right boundary is decremented.
    - **Bottom Row (if applicable):** Elements are added from right to left, then the bottom boundary is decremented.
    - **Left Column (if applicable):** Elements are added from bottom to top, then the left boundary is incremented.
5. **Final Result:** The collected elements are returned in the desired spiral order.

This solution ensures that the matrix is traversed correctly in a spiral order, taking into account all possible edge cases.
