#include <iostream>
#include <vector>
using namespace std;

bool checkSort(vector<int>& nums, int index) {
    if (index == nums.size() - 1) return true;
    if (nums[index] > nums[index + 1]) return false;
    return checkSort(nums, index + 1);
}

bool isSorted(vector<int>& nums) {
    return checkSort(nums, 0);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << (isSorted(nums) ? "Sorted" : "Not Sorted") << endl;
    return 0;
}