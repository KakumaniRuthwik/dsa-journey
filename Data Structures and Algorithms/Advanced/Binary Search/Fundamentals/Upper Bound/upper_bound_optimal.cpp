#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums, int x) {
    int size = nums.size();
    int low = 0, high = size - 1;
    int index = size; // default if not found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > x) {
            index = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    return index;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 5};
    int x = 2;
    cout << "Upper bound of " << x << " is at index: " << upperBound(nums, x) << endl;
    return 0;
}