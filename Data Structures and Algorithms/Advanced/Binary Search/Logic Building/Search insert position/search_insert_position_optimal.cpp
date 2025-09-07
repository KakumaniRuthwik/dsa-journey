#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target) {

    int size = nums.size();
    int low = 0;
    int high = size - 1;
    int position = size;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            position = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return position;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << "Insert position of " << target << " is: "
         << searchInsert(nums, target) << endl;

    target = 2;
    cout << "Insert position of " << target << " is: "
         << searchInsert(nums, target) << endl;

    target = 7;
    cout << "Insert position of " << target << " is: "
         << searchInsert(nums, target) << endl;

    target = 0;
    cout << "Insert position of " << target << " is: "
         << searchInsert(nums, target) << endl;

    return 0;
}