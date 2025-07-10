#include <iostream>
#include <vector>
using namespace std;

int countOddElements(const vector<int>& arr) {
    int count = 0;
    for(int num : arr){
        if(num % 2 != 0){
            count++;
        }
    }
    return count;
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

    cout << "Count of odd elements: " << countOddElements(arr) << endl;
    return 0;
}