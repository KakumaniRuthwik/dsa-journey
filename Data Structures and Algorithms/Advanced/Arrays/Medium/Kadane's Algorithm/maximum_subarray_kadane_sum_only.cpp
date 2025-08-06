#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, sum = 0;

    for (int num : nums) {
        sum += num;
        maxSum = max(maxSum, sum);
        if (sum < 0) sum = 0;
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max subarray sum (Kadane): " << maxSubArray(nums) << endl;
    return 0;
}