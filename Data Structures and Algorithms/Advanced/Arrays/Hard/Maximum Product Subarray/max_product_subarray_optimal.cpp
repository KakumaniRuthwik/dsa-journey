#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int size = nums.size();
    int maximumProduct = INT_MIN;
    int prefix = 1, suffix = 1;

    for (int index = 0; index < size; index++) {
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;

        prefix *= nums[index];
        suffix *= nums[size - index - 1];

        maximumProduct = max(maximumProduct, max(prefix, suffix));
    }
    return maximumProduct;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl;
    return 0;
}