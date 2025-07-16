#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        bool isSorted = true;

        for (int j = 0; j < n - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                isSorted = false;
            }
        }

        if (isSorted) {
            break;
        }
    }

    return nums;
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8};
    vector<int> sorted = bubbleSort(arr);

    for (int num : sorted) {
        cout << num << " ";
    }

    return 0;
}