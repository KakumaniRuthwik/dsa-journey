#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int size = nums.size();
    int count = 0;
    int majorityCandidate = nums[0];

    for (int index = 0; index < size; index++) {
        if (count == 0) {
            majorityCandidate = nums[index];
            count = 1;
        } else if (nums[index] == majorityCandidate) {
            count++;
        } else {
            count--;
        }
    }

    int verifyCount = 0;
    for (int index = 0; index < size; index++) {
        if (nums[index] == majorityCandidate) {
            verifyCount++;
        }
    }

    if (verifyCount > size / 2) {
        return majorityCandidate;
    }
    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums) << endl;
    return 0;
}