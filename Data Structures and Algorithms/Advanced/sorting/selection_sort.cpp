#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }

        swap(nums[i], nums[minIndex]);
    }

    return nums;
}

int main() {
    vector<int> arr = {4, 2, 1, 5, 3};
    vector<int> sorted = selectionSort(arr);

    for (int num : sorted) {
        cout << num << " ";
    }

    return 0;
}