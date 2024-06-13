#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        int lastElement = nums.back();
        int idx = mp[val];

        nums[idx] = lastElement;
        mp[lastElement] = idx;

        nums.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }

private:
    std::vector<int> nums;
    std::unordered_map<int, int> mp;
};

int main() {
    RandomizedSet randomizedSet;
    
    // Testing the RandomizedSet
    std::cout << std::boolalpha;  // to print true/false instead of 1/0
    std::cout << "Insert 1: " << randomizedSet.insert(1) << std::endl;  // true
    std::cout << "Remove 2: " << randomizedSet.remove(2) << std::endl;  // false
    std::cout << "Insert 2: " << randomizedSet.insert(2) << std::endl;  // true
    std::cout << "GetRandom: " << randomizedSet.getRandom() << std::endl; // 1 or 2
    std::cout << "Remove 1: " << randomizedSet.remove(1) << std::endl;  // true
    std::cout << "Insert 2: " << randomizedSet.insert(2) << std::endl;  // false
    std::cout << "GetRandom: " << randomizedSet.getRandom() << std::endl; // 2

    return 0;
}
