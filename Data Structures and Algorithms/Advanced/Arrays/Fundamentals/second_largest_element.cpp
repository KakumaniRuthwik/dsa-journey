#include <bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int>& nums) {
    int size = nums.size();

    if(size < 2){
        return -1;
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int index = 0; index < size; index++){
        if(nums[index] > largest){
            secondLargest = largest;
            largest = nums[index];
        } else if(nums[index] > secondLargest && nums[index] != largest){
            secondLargest = nums[index];
        }
    }

    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}

int main() {
    vector<int> nums = {10, 5, 20, 8};
    cout << "Second Largest Element: " << secondLargestElement(nums) << endl;
    return 0;
}