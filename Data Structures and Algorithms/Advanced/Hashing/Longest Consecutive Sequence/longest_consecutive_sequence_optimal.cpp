#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> uniqueValues(nums.begin(), nums.end());
    int longestSequence = 1;

    for (int value : uniqueValues) {
        if (uniqueValues.find(value - 1) == uniqueValues.end()) {
            int temp = value;
            int count = 1;

            while (uniqueValues.find(temp + 1) != uniqueValues.end()) {
                temp++;
                count++;
            }

            longestSequence = max(longestSequence, count);
        }
    }

    return longestSequence;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl; // Output: 4
}