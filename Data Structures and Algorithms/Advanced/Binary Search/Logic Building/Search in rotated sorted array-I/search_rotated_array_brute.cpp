#include <bits/stdc++.h>
using namespace std;

// Brute Force: Linear Search
int searchBrute(vector<int> &nums, int k) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == k) return i;
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int k = 0;

    int index = searchBrute(nums, k);
    cout << "Index of " << k << " is: " << index << endl;

    return 0;
}