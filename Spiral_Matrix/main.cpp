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
