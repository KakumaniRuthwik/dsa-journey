#include<iostream>
#include<vector>
using namespace std;

int sumOfArray(vector<int>& arr) {
    int sum = 0;
    for(int num : arr){
        sum += num;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Sum of array elements: " << sumOfArray(arr) << endl;
    return 0;
}