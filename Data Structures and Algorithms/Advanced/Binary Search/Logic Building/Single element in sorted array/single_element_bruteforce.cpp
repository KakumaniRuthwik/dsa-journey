#include <bits/stdc++.h>
using namespace std;

// Brute-force: check elements in pairs
int singleNonDuplicateBrute(const vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i += 2) {
        if (nums[i] != nums[i + 1]) {
            return nums[i];
        }
    }
    return nums[n - 1]; // single element is at the end
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << singleNonDuplicateBrute(nums) << "\n";
    return 0;
}