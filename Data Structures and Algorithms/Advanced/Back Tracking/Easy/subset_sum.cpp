#include <iostream>
#include <vector>
using namespace std;

bool subsequenceSum(vector<int>& nums, int size, int target, int index, int sum) {
    if (sum == target)
        return true;

    if (index == size)
        return false;

    // Include the current element
    if (subsequenceSum(nums, size, target, index + 1, sum + nums[index]))
        return true;

    // Exclude the current element
    if (subsequenceSum(nums, size, target, index + 1, sum))
        return true;

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 8;

    if (subsequenceSum(nums, nums.size(), k, 0, 0))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
