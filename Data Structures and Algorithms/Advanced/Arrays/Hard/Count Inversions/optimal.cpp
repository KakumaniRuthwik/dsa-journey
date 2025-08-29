#include<iostream>
#include<vector>

using namespace std;

long long int numberOfInversions(vector<int>& nums){

    int size = nums.size();

    return mergeSort(nums, 0, size - 1);
}


long long int merge(vector<int>& nums, int low, int mid, int high){

    vector<int> temp;

    int left = low; 
    int right = mid + 1;

    long long int count = 0;

    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
            count += (mid - left + 1);
        }
    }

    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }

    return count;
}

long long int mergeSort(vector<int>& nums, int low, int high){

    long long int count = 0;

    if(low < high){
        int mid = low + (high - low) / 2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);
    }

    return count;
}

int main() {
    vector<int> nums = {2, 4, 1, 3, 5};
    cout << numberOfInversions(nums) << endl;
    return 0;
}