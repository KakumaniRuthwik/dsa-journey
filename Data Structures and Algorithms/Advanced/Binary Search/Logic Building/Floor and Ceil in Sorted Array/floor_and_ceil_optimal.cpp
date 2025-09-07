#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Find the smallest number >= target
    int findCeil(vector<int>& nums, int size, int target){
        int ceil = -1;
        int low = 0, high = size - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                ceil = nums[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ceil;
    }

    // Find the largest number <= target
    int findFloor(vector<int>& nums, int size, int target){
        int floor = -1;
        int low = 0, high = size - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target){
                floor = nums[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return floor;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int size = nums.size();
        int floor = findFloor(nums, size, x);
        int ceil = findCeil(nums, size, x);
        return {floor, ceil};
    }
};

int main() {
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;

    Solution sol;
    vector<int> result = sol.getFloorAndCeil(nums, x);
    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;

    return 0;
}