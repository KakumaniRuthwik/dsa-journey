#include <iostream>
#include <vector>
using namespace std;

int missing_number(vector<int>& nums) {
    int size = nums.size();
    int xor1 = 0, xor2 = 0;

    for (int index = 0; index < size; index++) {
        xor1 ^= (index + 1);
        xor2 ^= nums[index];
    }

    return xor1 ^ xor2;
}

int main() {
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number: " << missing_number(nums) << endl;
    return 0;
}