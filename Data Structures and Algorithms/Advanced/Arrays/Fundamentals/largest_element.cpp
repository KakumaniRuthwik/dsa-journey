#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& nums) {
    int size = nums.size();

    if(size == 0){
        return -1; // or throw an error based on problem statement
    }

    int largest = INT_MIN;

    for(int index = 0; index < size; index++){
        if(nums[index] > largest){
            largest = nums[index];
        }
    }

    return largest;
}

int main() {
    vector<int> nums = {10, 5, 20, 8};
    cout << "Largest Element: " << largestElement(nums) << endl;
    return 0;
}