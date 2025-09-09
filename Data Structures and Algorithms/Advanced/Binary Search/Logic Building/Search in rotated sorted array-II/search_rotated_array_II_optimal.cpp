#include <bits/stdc++.h>
using namespace std;

// Optimal binary search in rotated sorted array with duplicates
bool searchRotatedWithDup(const vector<int>& nums, int target) {
    int low = 0, high = (int)nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return true;

        // Handle duplicates at both ends
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            ++low; --high;
            continue;
        }

        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k; cin >> k;

    bool found = searchRotatedWithDup(nums, k);
    cout << (found ? "true\n" : "false\n");
    return 0;
}