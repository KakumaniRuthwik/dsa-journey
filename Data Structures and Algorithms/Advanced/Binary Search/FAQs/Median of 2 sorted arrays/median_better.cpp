#include <bits/stdc++.h>
using namespace std;

double findMedianBetter(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    int total = n1 + n2;

    int index1 = (total - 1) / 2; 
    int index2 = total / 2;       

    int i = 0, j = 0, count = 0;
    int val1 = -1, val2 = -1;

    while (i < n1 && j < n2) {
        int pick;
        if (arr1[i] <= arr2[j]) pick = arr1[i++];
        else pick = arr2[j++];

        if (count == index1) val1 = pick;
        if (count == index2) val2 = pick;
        count++;
    }

    while (i < n1) {
        int pick = arr1[i++];
        if (count == index1) val1 = pick;
        if (count == index2) val2 = pick;
        count++;
    }

    while (j < n2) {
        int pick = arr2[j++];
        if (count == index1) val1 = pick;
        if (count == index2) val2 = pick;
        count++;
    }

    if (total % 2 == 1) return val2;
    return (val1 + val2) / 2.0;
}

int main() {
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2};

    cout << "Median (Better): " << findMedianBetter(arr1, arr2) << endl;
    return 0;
}
