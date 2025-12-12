#include <bits/stdc++.h>
using namespace std;

int subsequenceCount(vector<int>& nums, int index, int sum, int target) {
    if(sum == target) return 1;
    if(sum > target || index == nums.size()) return 0;

    int include = subsequenceCount(nums, index + 1, sum + nums[index], target);
    int exclude = subsequenceCount(nums, index + 1, sum, target);

    return include + exclude;
}

int main() {
    vector<int> nums = {4, 9, 2, 5, 1};
    int k = 10;

    int result = subsequenceCount(nums, 0, 0, k);

    cout << "Count of subsequences = " << result << endl;
    return 0;
}
