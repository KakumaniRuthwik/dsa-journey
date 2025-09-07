#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums, int x) {
    int size = nums.size();
    int index = size; // default if not found

    for (int i = 0; i < size; i++) {
        if (nums[i] > x) {
            index = i;
            break;
        }
    }
    return index;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 5};
    int x = 2;
    cout << "Upper bound of " << x << " is at index: " << upperBound(nums, x) << endl;
    return 0;
}