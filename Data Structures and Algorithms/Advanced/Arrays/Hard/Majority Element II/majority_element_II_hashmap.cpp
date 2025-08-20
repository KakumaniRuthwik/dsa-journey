#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> frequencyCount;
        vector<int> result;

        for (auto value : nums) {
            frequencyCount[value]++;
        }

        for (auto& [num, count] : frequencyCount) {
            if (count > n / 3) {
                result.push_back(num);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 3};
    vector<int> ans = s.majorityElement(nums);

    for (int x : ans) cout << x << " ";
    return 0;
}