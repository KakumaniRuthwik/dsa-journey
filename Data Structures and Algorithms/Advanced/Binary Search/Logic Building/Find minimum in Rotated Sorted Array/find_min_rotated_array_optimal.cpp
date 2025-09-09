#include <bits/stdc++.h>
using namespace std;

// Optimal: binary search for minimum in rotated sorted array (distinct values)
int findMinRotatedOptimal(const vector<int>& nums) {
    int low = 0, high = (int)nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // If mid element > rightmost, min must be to the right of mid
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            // Otherwise, min is at mid or to the left of mid
            high = mid;
        }
    }
    // low == high is the index of the minimum
    return nums[low];
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << findMinRotatedOptimal(nums) << "\n";
    return 0;
}