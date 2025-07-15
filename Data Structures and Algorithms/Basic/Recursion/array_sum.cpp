#include <iostream>
#include <vector>
using namespace std;

int sum(const vector<int>& nums, int index) {
    if (nums.empty()) {
        return 0;
    }

    if (index == nums.size()) {
        return 0;
    }

    return nums[index] + sum(nums, index + 1);
}

int arraySum(const vector<int>& nums) {
    return sum(nums, 0);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Sum of array: " << arraySum(nums) << endl;
    return 0;
}