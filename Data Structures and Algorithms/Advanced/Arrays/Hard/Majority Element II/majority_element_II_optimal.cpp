#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element1 = 0, element2 = 0;
        int count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == element1) {
                count1++;
            } else if (num == element2) {
                count2++;
            } else if (count1 == 0) {
                element1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                element2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (int num : nums) {
            if (num == element1) count1++;
            else if (num == element2) count2++;
        }

        vector<int> result;
        int threshold = n / 3;
        if (count1 > threshold) result.push_back(element1);
        if (count2 > threshold) result.push_back(element2);

        sort(result.begin(), result.end()); // ascending order
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 1, 3, 2, 2, 3};
    Solution s;
    vector<int> ans = s.majorityElement(nums);
    for (int x : ans) cout << x << " ";
    return 0;
}