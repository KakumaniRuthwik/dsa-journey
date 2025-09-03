#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int k) {
    int size = nums.size();
    int maxLength = 0;

    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = i; j < size; j++) {
            sum += nums[j];
            if (sum == k) {
                int currLength = j - i + 1;
                maxLength = max(maxLength, currLength);
            }
        }
    }
    return maxLength;
}

int main() {
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << longestSubarray(nums, k) << endl; // Output: 4
    return 0;
}