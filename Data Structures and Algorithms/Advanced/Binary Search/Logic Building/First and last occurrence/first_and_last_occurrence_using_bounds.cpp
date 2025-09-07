#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Custom lowerBound: finds the first index where nums[i] >= target
    int lowerBound(vector<int>& nums, int size, int target){
        int low = 0, high = size - 1;
        int start = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                start = mid;
                high = mid - 1;  // search left
            }else{
                low = mid + 1;
            }
        }
        return start;
    }

    // Custom upperBound: finds the last index where nums[i] <= target
    int upperBound(vector<int>& nums, int size, int target){
        int low = 0, high = size - 1;
        int end = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target){
                end = mid;
                low = mid + 1;  // search right
            }else{
                high = mid - 1;
            }
        }
        return end;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int size = nums.size();

        int start = lowerBound(nums, size, target);
        int end = upperBound(nums, size, target);

        // Ensure target actually exists in the array
        if(start == -1 || end == -1 || nums[start] != target || nums[end] != target){
            return {-1, -1};
        }

        return {start, end};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution sol;
    vector<int> result = sol.searchRange(nums, target);
    cout << "Start: " << result[0] << ", End: " << result[1] << endl;

    return 0;
}