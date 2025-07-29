#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void move_zeroes_two_pointers(vector<int>& nums) {
    int size = nums.size();
    int pos1 = 0, pos2 = 1;

    while (pos2 < size) {
        if (nums[pos1] != 0) {
            pos1++;
            if (pos2 <= pos1)
                pos2 = pos1 + 1;
        } else if (nums[pos2] != 0) {
            swap(nums[pos1], nums[pos2]);
            pos1++;
            pos2++;
        } else {
            pos2++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    move_zeroes_two_pointers(nums);

    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}