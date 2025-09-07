#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int firstOccurrence(vector<int>& nums, int size, int target){
        int low = 0, high = size - 1, first = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                first = mid;
                high = mid - 1;  // keep searching left
            } else if(nums[mid] > target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return first;
    }

    int lastOccurrence(vector<int>& nums, int size, int target){
        int low = 0, high = size - 1, last = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                last = mid;
                low = mid + 1;  // keep searching right
            } else if(nums[mid] > target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int size = nums.size();
        int start = firstOccurrence(nums, size, target);
        int end = lastOccurrence(nums, size, target);
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