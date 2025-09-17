#include <bits/stdc++.h>
using namespace std;

int findPeakElementLinear(vector<int> &arr) {
    int size = arr.size();

    if (size == 1) return 0;

    if (arr[0] > arr[1]) return 0;
    if (arr[size - 1] > arr[size - 2]) return size - 1;

    for (int i = 1; i < size - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    cout << "Peak found at index: " << findPeakElementLinear(arr) << endl;
    return 0;
}
