#include <iostream>
#include <vector>
using namespace std;

// Partition function using Lomuto-style logic with Hoare's touches
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right) {
        while (left <= high && arr[left] <= pivot) left++;
        while (right >= low && arr[right] > pivot) right--;
        if (left < right)
            swap(arr[left], arr[right]);
    }

    swap(arr[low], arr[right]);
    return right;
}

// Recursive Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    vector<int> nums = {9, 3, 7, 5, 6, 4, 8, 2};
    int n = nums.size();

    quickSort(nums, 0, n - 1);

    cout << "Sorted Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}