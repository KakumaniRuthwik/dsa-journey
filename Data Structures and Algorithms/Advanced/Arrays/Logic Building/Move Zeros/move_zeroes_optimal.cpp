#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void move_zeroes_optimal(vector<int>& nums) {
    int pos1 = 0;

    for (int pos2 = 0; pos2 < nums.size(); pos2++) {
        if (nums[pos2] != 0) {
            swap(nums[pos1], nums[pos2]);
            pos1++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    move_zeroes_optimal(nums);

    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}