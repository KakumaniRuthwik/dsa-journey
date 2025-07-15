#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }

    swap(nums[left], nums[right]);
    reverse(nums, left + 1, right - 1);
}

vector<int> reverseArray(vector<int>& nums) {
    reverse(nums, 0, nums.size() - 1);
    return nums;
}

// Example usage
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> reversed = reverseArray(nums);

    for (int num : reversed) {
        cout << num << " ";
    }

    return 0;
}