#include <bits/stdc++.h>
using namespace std;

// Brute-force: scan array to detect the "drop" point
int findKRotationBrute(const vector<int>& nums) {
    int n = nums.size();
    int rotationCount = 0;

    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] < nums[i]) {
            rotationCount = i + 1;
            break; // early exit since pivot found
        }
    }
    return rotationCount;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << findKRotationBrute(nums) << "\n";
    return 0;
}