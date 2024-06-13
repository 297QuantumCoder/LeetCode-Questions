#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(const string &s, int numRows) {
    // If numRows is 1 or the string length is less than or equal to 1, return the string as is.
    if (numRows <= 1 || s.size() <= 1) {
        return s;
    }

    // Initialize a vector of strings to store the characters of each row.
    vector<string> rows(min(numRows, int(s.size())));
    int currentRow = 0;
    bool goingDown = false;

    // Iterate through each character in the string.
    for (char c : s) {
        rows[currentRow] += c; // Add the current character to the current row.
        
        // If we are at the first or the last row, reverse the direction.
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }
        
        // Move to the next row based on the current direction.
        currentRow += goingDown ? 1 : -1;
    }

    // Concatenate all rows to get the final result.
    string result;
    for (const string &row : rows) {
        result += row;
    }
    return result;
}

int main() {
    // Example 1
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << convert(s1, numRows1) << endl; // Output: PAHNAPLSIIGYIR

    // Example 2
    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << convert(s2, numRows2) << endl; // Output: PINALSIGYAHRPI

    // Example 3
    string s3 = "A";
    int numRows3 = 1;
    cout << convert(s3, numRows3) << endl; // Output: A

    return 0;
}
