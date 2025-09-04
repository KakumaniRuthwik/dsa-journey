#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int longestSubarray(vector<int>& nums, int target){

    // size of nums
    int size = nums.size();

    if(size == 0){
        return 0;
    }

    int sum = 0, longest = 0;

    unordered_map<int, int> prefixSum;

    for(int index = 0; index < size; index++){
        
        sum += nums[index];

        if(sum == target){
            longest = max(longest, index + 1);
        }

        int rem = sum - target;

        if(prefixSum.find(rem) != prefixSum.end()){
            int length = index - prefixSum[rem];
            longest = max(length, longest);
        }

        if(prefixSum.find(sum) == prefixSum.end()){
            prefixSum[sum] = index;
        }
    }

    return longest;
}

int main(){

    vector<int> nums = {1,2,3,4,5};
    cout << "Longest sub array with target: 5 is " << longestSubarray(nums, 5);
    
    return 0;
}