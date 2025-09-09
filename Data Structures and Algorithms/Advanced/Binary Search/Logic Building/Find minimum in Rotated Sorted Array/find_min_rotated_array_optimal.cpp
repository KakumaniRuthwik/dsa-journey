#include <bits/stdc++.h>
using namespace std;

int findMinRotatedOptimal(vector<int>& nums) {
    int low = 0, high = (int)nums.size() - 1;
    int minimum = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If left half is sorted
        if (nums[low] <= nums[mid]) {
            minimum = min(minimum, nums[low]);
            low = mid + 1;
        }
        // If right half is sorted
        else {
            minimum = min(minimum, nums[mid]);
            high = mid - 1;
        }
    }
    return minimum;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << findMinRotatedOptimal(nums) << "\n";
    return 0;
}