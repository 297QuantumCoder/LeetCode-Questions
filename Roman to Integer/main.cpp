#include <iostream>
#include <unordered_map>
#include <string>

int romanToInt(const std::string& s) {
    std::unordered_map<char, int> romanValues = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        int current = romanValues[s[i]];
        int next = (i < n - 1) ? romanValues[s[i + 1]] : 0;

        if (current < next) {
            total -= current;
        } else {
            total += current;
        }
    }

    return total;
}

int main() {
    std::string s1 = "III";
    std::string s2 = "LVIII";
    std::string s3 = "MCMXCIV";

    std::cout << "Input: " << s1 << " Output: " << romanToInt(s1) << std::endl;
    std::cout << "Input: " << s2 << " Output: " << romanToInt(s2) << std::endl;
    std::cout << "Input: " << s3 << " Output: " << romanToInt(s3) << std::endl;

    return 0;
}
