#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    // Merge both halves
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left++]);
        } else {
            temp.push_back(nums[right++]);
        }
    }

    // Add remaining elements
    while (left <= mid) {
        temp.push_back(nums[left++]);
    }

    while (right <= high) {
        temp.push_back(nums[right++]);
    }

    // Copy sorted temp back to original array
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

// Driver code
int main() {
    vector<int> nums = {4, 2, 1, 5, 3};

    mergeSort(nums, 0, nums.size() - 1);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}