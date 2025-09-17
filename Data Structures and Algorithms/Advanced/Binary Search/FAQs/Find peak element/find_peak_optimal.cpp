#include <bits/stdc++.h>
using namespace std;

int findPeakElementBinary(vector<int> &arr) {
    int size = arr.size();

    if (size == 1) return 0;

    if (arr[0] > arr[1]) return 0;
    if (arr[size - 1] > arr[size - 2]) return size - 1;

    int low = 1, high = size - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        if (arr[mid] > arr[mid - 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    cout << "Peak found at index: " << findPeakElementBinary(arr) << endl;
    return 0;
}
