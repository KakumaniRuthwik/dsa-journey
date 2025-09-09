#include <bits/stdc++.h>
using namespace std;

int findMinRotatedBrute(const vector<int>& nums) {
    int minimum = INT_MAX;
    for (int index = 0; index < (int)nums.size(); index++) {
        if (nums[index] < minimum) {
            minimum = nums[index];
        }
    }
    return minimum;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << findMinRotatedBrute(nums) << "\n";
    return 0;
}