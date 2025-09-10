#include <bits/stdc++.h>
using namespace std;

// Optimal: binary search to find index of minimum element = rotation count
int findKRotationOptimal(const vector<int>& nums) {
    int low = 0, high = (int)nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high]) {
            // Minimum lies strictly to the right of mid
            low = mid + 1;
        } else {
            // Minimum is at mid or to the left
            high = mid;
        }
    }
    return low; // index of minimum element = number of rotations
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << findKRotationOptimal(nums) << "\n";
    return 0;
}