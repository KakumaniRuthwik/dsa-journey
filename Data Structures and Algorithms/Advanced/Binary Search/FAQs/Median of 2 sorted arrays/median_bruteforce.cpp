#include <bits/stdc++.h>
using namespace std;

double findMedianBrute(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    merged.reserve(arr1.size() + arr2.size());

    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) merged.push_back(arr1[i++]);
    while (j < arr2.size()) merged.push_back(arr2[j++]);

    int n = merged.size();
    if (n % 2 == 1) {
        return merged[n / 2];
    }
    return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
}

int main() {
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2};

    cout << "Median (Brute): " << findMedianBrute(arr1, arr2) << endl;
    return 0;
}
