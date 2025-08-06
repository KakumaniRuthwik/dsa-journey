#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArrayBrute(vector<int>& nums) {
    int maxSum = INT_MIN;
    int size = nums.size();

    for (int start = 0; start < size; ++start) {
        int sum = 0;
        for (int end = start; end < size; ++end) {
            sum += nums[end];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max subarray sum (Brute): " << maxSubArrayBrute(nums) << endl;
    return 0;
}