#include <bits/stdc++.h>
using namespace std;

int binarySearchRecursive(vector<int>& nums, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (nums[mid] == target) return mid;
    else if (nums[mid] > target) return binarySearchRecursive(nums, low, mid - 1, target);
    else return binarySearchRecursive(nums, mid + 1, high, target);
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 9;

    int result = binarySearchRecursive(nums, 0, nums.size() - 1, target);
    cout << "Target found at index: " << result << endl;
}