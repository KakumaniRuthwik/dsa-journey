#include <iostream>
#include <vector>
using namespace std;

void rotate_array_by_one(vector<int>& nums) {
    int size = nums.size();
    if (size <= 1) return;

    int temp = nums[0];
    for (int index = 0; index < size - 1; index++) {
        nums[index] = nums[index + 1];
    }
    nums[size - 1] = temp;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    rotate_array_by_one(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}