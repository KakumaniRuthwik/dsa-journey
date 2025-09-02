#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& nums, int value) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] == value) {
            return true;
        }
    }
    return false;
}

int longestConsecutive(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;

    int longest = 1;

    for (int i = 0; i < size; i++) {
        int value = nums[i];
        int count = 1;

        while (linearSearch(nums, value + 1)) {
            count++;
            value++;
        }

        longest = max(longest, count);
    }

    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;
    return 0;
}