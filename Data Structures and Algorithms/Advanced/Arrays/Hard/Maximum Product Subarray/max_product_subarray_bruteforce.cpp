#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int size = nums.size();
    int maxProduct = INT_MIN;

    for (int i = 0; i < size; i++) {
        int product = 1;
        for (int j = i; j < size; j++) {
            product *= nums[j];
            maxProduct = max(maxProduct, product);
        }
    }
    return maxProduct;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl;
    return 0;
}