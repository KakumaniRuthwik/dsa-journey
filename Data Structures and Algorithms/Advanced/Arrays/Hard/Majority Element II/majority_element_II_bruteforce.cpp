#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int count = 0;

            // Skip if already added to result
            if (!result.empty() && result[0] == nums[i]) continue;
            if (result.size() == 2 && (result[0] == nums[i] || result[1] == nums[i])) continue;

            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) count++;
            }

            if (count > n / 3) {
                result.push_back(nums[i]);
                if (result.size() == 2) break;
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