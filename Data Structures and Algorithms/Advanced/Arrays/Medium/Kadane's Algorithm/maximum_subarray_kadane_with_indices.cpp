#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    int maxSum = INT_MIN, sum = 0;
    int tempStart = 0, startIndex = 0, endIndex = 0;

    for (int index = 0; index < size; index++) {
        sum += nums[index];

        if (sum > maxSum) {
            maxSum = sum;
            startIndex = tempStart;
            endIndex = index;
        }

        if (sum < 0) {
            sum = 0;
            tempStart = index + 1;
        }
    }

    cout << "Subarray with max sum: [";
    for (int i = startIndex; i <= endIndex; i++) {
        cout << nums[i] << (i == endIndex ? "]\n" : ", ");
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = maxSubArray(nums);
    cout << "Maximum subarray sum: " << maxSum << endl;
    return 0;
}