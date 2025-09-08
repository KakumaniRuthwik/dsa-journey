#include <bits/stdc++.h>
using namespace std;

// Optimal: Binary Search in Rotated Sorted Array
int searchOptimal(vector<int> &nums, int k) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == k) return mid;

        // Left half sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= k && k < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half sorted
        else {
            if (nums[mid] < k && k <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int k = 0;

    int index = searchOptimal(nums, k);
    cout << "Index of " << k << " is: " << index << endl;

    return 0;
}