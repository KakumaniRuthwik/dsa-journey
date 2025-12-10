#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void makeSubsets(vector<int>& nums, vector<int>& arr, int size, int index, vector<vector<int>>& result) {
        if (index == size) {
            result.push_back(arr);
            return;
        }

        // Include nums[index]
        arr.push_back(nums[index]);
        makeSubsets(nums, arr, size, index + 1, result);

        // Exclude nums[index]
        arr.pop_back();
        makeSubsets(nums, arr, size, index + 1, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> result;
        makeSubsets(nums, arr, nums.size(), 0, result);
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution s;
    vector<vector<int>> ans = s.subsets(nums);

    cout << "Subsets:\n";
    for (auto &subset : ans) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}