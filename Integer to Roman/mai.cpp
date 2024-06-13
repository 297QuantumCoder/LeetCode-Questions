#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num) {
    // Define the Roman numeral symbols and their values
    vector<pair<int, string>> romanSymbols = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
        {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    string result = "";
    
    // Iterate over the Roman numeral symbols and values
    for (const auto &symbol : romanSymbols) {
        // Append the corresponding Roman numeral symbol while num is greater or equal to its value
        while (num >= symbol.first) {
            result += symbol.second;
            num -= symbol.first;
        }
    }
    
    return result;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    cout << "Roman numeral: " << intToRoman(num) << endl;
    
    return 0;
}
