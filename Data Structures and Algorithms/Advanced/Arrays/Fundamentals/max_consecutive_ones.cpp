#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int size = nums.size();
    if (size < 1) return 0;

    int countOnesMax = 0;
    int countOnes = 0;

    for (int index = 0; index < size; index++) {
        if (nums[index] == 1) {
            countOnes++;
            countOnesMax = max(countOnesMax, countOnes);
        } else {
            countOnes = 0;
        }
    }

    return countOnesMax;
}

// Sample driver for testing
int main() {
    vector<int> nums = {1, 0, 1, 1, 1, 0, 1, 1};
    cout << "Max Consecutive 1s: " << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}