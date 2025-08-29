#include<iostream>
#include<vector>

using namespace std;

int merge(vector<int>& nums, int low, int mid, int high){

    int right = mid + 1;

    int count = 0;

    for(int i = low; i <= mid; i++){
        while(right <= high && (long long)nums[i] > (2LL * nums[right])){
            right++;
        }

        count += (right - (mid + 1));
    }

    int left = low;
    right = mid + 1;

    vector<int> temp;

    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
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

int mergeSort(vector<int>& nums, int low, int high){

    int count = 0;

    if(low < high){

        int mid = low + (high - low) / 2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);
    }

    return count;
}

int reversePairs(vector<int>& nums){

    int size = nums.size();

    return mergeSort(nums, 0, size - 1);
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << reversePairs(nums) << endl;
    return 0;
}