#include<iostream>
#include<vector>

using namespace std;


// Function to find the longest subarray with sum = target
// Works only when all numbers in nums[] are positive or non-negative
int longestSubarray(vector<int>& nums, int target){

    int size = nums.size();

    int sum = 0;
    int left = 0, right = 0;
    int longest = 0;

    while(right < size){
        int length = 0;

        sum += nums[right];

        if(sum == target){
            length = right - left + 1;
            longest = max(length, longest);
        }

        while(sum > target && left <= right){
            sum -= nums[left];
            left++;
        }

        right++;
    }

    return longest;
}

int main(){

    vector<int> nums = {1,2,3,4,5};

    cout << "Longest sub array with target: 5 is " << longestSubarray(nums, 5);
}