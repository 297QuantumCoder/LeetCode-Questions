#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    int index = 0;

    while (index < n) {
        // Determine how many words fit into the current line
        int totalChars = words[index].size();
        int last = index + 1;

        while (last < n) {
            if (totalChars + 1 + words[last].size() > maxWidth) break;
            totalChars += 1 + words[last].size();
            last++;
        }

        string line;
        int numberOfWords = last - index;

        if (last == n || numberOfWords == 1) {
            // Left justify for the last line or when there's only one word
            for (int i = index; i < last; ++i) {
                line += words[i];
                if (i < last - 1) line += " ";
            }
            while (line.size() < maxWidth) {
                line += " ";
            }
        } else {
            // Fully justify the current line
            int totalSpaces = maxWidth - totalChars + (numberOfWords - 1);
            int spaceBetweenWords = totalSpaces / (numberOfWords - 1);
            int extraSpaces = totalSpaces % (numberOfWords - 1);

            for (int i = index; i < last - 1; ++i) {
                line += words[i];
                for (int j = 0; j < (spaceBetweenWords + (i - index < extraSpaces)); ++j) {
                    line += " ";
                }
            }
            line += words[last - 1]; // Add the last word
        }

        result.push_back(line);
        index = last; // Move to the next set of words
    }

    return result;
}

int main() {
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    vector<string> result1 = fullJustify(words1, maxWidth1);

    for (const auto& line : result1) {
        cout << "\"" << line << "\"" << endl;
    }

    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth2 = 16;
    vector<string> result2 = fullJustify(words2, maxWidth2);

    for (const auto& line : result2) {
        cout << "\"" << line << "\"" << endl;
    }

    vector<string> words3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth3 = 20;
    vector<string> result3 = fullJustify(words3, maxWidth3);

    for (const auto& line : result3) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}
 