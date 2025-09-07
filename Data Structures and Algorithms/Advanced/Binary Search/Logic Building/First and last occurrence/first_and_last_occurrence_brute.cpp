#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int size = nums.size();
        int start = -1, end = -1;

        for(int index = 0; index < size; index++){
            if(nums[index] == target){
                if(start == -1){
                    start = index;
                }
                end = index;
            }
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