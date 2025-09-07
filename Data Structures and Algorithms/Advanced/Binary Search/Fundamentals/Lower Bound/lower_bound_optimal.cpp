#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int x) {
    int size = nums.size();
    int low = 0, high = size - 1;
    int index = size; // default if not found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= x) {
            index = mid;
            high = mid - 1; // keep searching left
        } else {
            low = mid + 1; // search right
        }
    }
    return index;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 5};
    int x = 2;
    cout << "Lower bound of " << x << " is at index: " << lowerBound(nums, x) << endl;
    return 0;
}