#include <bits/stdc++.h>
using namespace std;

// Reverses the array from index 'start' to 'end'
void reverse_array(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        ++start;
        --end;
    }
}

// Rotates the array to the right by k steps
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    // Step 1: Reverse the last k elements
    reverse_array(nums, n - k, n - 1);

    // Step 2: Reverse the first n - k elements
    reverse_array(nums, 0, n - k - 1);

    // Step 3: Reverse the whole array
    reverse_array(nums, 0, n - 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}