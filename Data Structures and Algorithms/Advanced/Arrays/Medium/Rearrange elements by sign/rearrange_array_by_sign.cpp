#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int size = nums.size();
    vector<int> result(size, 0);
    int positiveIndex = 0, negativeIndex = 1;

    for (int index = 0; index < size; index++) {
        if (nums[index] < 0) {
            result[negativeIndex] = nums[index];
            negativeIndex += 2;
        } else {
            result[positiveIndex] = nums[index];
            positiveIndex += 2;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> result = rearrangeArray(nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}