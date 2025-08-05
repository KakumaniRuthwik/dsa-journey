#include <iostream>
#include <vector>
using namespace std;

void sortZeroOneTwo(vector<int>& nums) {
    int size = nums.size();
    int countZeros = 0, countOnes = 0, countTwos = 0;

    // Count number of 0s, 1s and 2s
    for (int i = 0; i < size; i++) {
        if (nums[i] == 0) countZeros++;
        else if (nums[i] == 1) countOnes++;
        else countTwos++;
    }

    // Overwrite the array
    for (int i = 0; i < countZeros; i++) nums[i] = 0;
    for (int i = countZeros; i < countZeros + countOnes; i++) nums[i] = 1;
    for (int i = countZeros + countOnes; i < size; i++) nums[i] = 2;
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortZeroOneTwo(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}