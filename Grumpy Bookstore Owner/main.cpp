#include <iostream>
#include <vector>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int totalSatisfied = 0;

    // Calculate the number of satisfied customers without using the technique
    for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            totalSatisfied += customers[i];
        }
    }

    // Calculate the additional satisfied customers if we use the technique
    int additionalSatisfied = 0;
    int maxAdditionalSatisfied = 0;

    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i] == 1) {
            additionalSatisfied += customers[i];
        }
    }
    maxAdditionalSatisfied = additionalSatisfied;

    // Sliding window to find the maximum additional satisfied customers
    for (int i = minutes; i < n; ++i) {
        if (grumpy[i] == 1) {
            additionalSatisfied += customers[i];
        }
        if (grumpy[i - minutes] == 1) {
            additionalSatisfied -= customers[i - minutes];
        }
        maxAdditionalSatisfied = max(maxAdditionalSatisfied, additionalSatisfied);
    }

    return totalSatisfied + maxAdditionalSatisfied;
}

int main() {
    vector<int> customers1 = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy1 = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes1 = 3;
    cout << "Example 1 Output: " << maxSatisfied(customers1, grumpy1, minutes1) << endl; // Output: 16

    vector<int> customers2 = {1};
    vector<int> grumpy2 = {0};
    int minutes2 = 1;
    cout << "Example 2 Output: " << maxSatisfied(customers2, grumpy2, minutes2) << endl; // Output: 1

    return 0;
}
