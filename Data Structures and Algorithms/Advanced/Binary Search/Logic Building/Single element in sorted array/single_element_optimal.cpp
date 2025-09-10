#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int size = nums.size();

    // Edge cases
    if (size == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[size - 1] != nums[size - 2]) return nums[size - 1];

    int low = 1, high = size - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // Left side is even-length → single lies on right
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
            (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Should never reach here
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << "Single element: " << singleNonDuplicate(nums) << endl;
    return 0;
}
