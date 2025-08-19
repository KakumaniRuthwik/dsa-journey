#include<iostream>
#include<vector>
using namespace std;

void nextPermutation(vector<int>& nums){

    int size = nums.size();

    int pivotIndex = -1;

    for(int index = size - 2; index >= 0; index--){
        if(nums[index] < nums[index + 1]){
            pivotIndex = index;
            break;
        }
    }

    if(pivotIndex == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int index = size - 1; index > pivotIndex; index--){
        if(nums[index] > nums[pivotIndex]){
            swap(nums[index], nums[pivotIndex]);
            break;
        }
    }

    reverse(nums.begin() + pivotIndex + 1, nums.end());
    return;
}

int main(){

    vector<int> nums = {1,2,3};

    nextPermutation(nums);

    int size = nums.size();

    for(int index = 0; index < size; index++){
        cout << nums[index] << " ";
    }

    cout << endl;

    return 0;
    
}