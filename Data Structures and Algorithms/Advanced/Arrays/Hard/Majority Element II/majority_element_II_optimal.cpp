#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int cand1 = 0, cand2 = 0;
    int cnt1 = 0, cnt2 = 0;

    // First pass: Find potential candidates
    for (int num : nums) {
        if (num == cand1) {
            cnt1++;
        } else if (num == cand2) {
            cnt2++;
        } else if (cnt1 == 0) {
            cand1 = num;
            cnt1 = 1;
        } else if (cnt2 == 0) {
            cand2 = num;
            cnt2 = 1;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    // Second pass: Validate candidates
    cnt1 = cnt2 = 0;
    for (int num : nums) {
        if (num == cand1) cnt1++;
        else if (num == cand2) cnt2++;
    }

    vector<int> result;
    if (cnt1 > n / 3) result.push_back(cand1);
    if (cnt2 > n / 3) result.push_back(cand2);

    return result;
}

int main() {
    vector<int> nums = {3,2,3};
    vector<int> ans = majorityElement(nums);
    for (int x : ans) cout << x << " ";
    return 0;
}