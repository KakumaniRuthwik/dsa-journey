#include <iostream>
#include <vector>
using namespace std;

void move_zeroes_brute_force(vector<int>& nums) {
    vector<int> temp;

    for (int num : nums) {
        if (num != 0)
            temp.push_back(num);
    }

    int index = 0;
    for (int num : temp)
        nums[index++] = num;

    while (index < nums.size())
        nums[index++] = 0;
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    move_zeroes_brute_force(nums);

    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}