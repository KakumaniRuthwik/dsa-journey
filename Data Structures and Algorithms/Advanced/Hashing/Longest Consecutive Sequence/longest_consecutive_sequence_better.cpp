#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;

    sort(nums.begin(), nums.end());

    int count = 1, longestSequence = 1;

    for (int i = 0; i < size - 1; i++) {
        if (nums[i] == nums[i + 1] - 1) {
            count++;
        } else if (nums[i] != nums[i + 1]) {
            count = 1;
        }
        longestSequence = max(longestSequence, count);
    }

    return longestSequence;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl; // Output: 4
}