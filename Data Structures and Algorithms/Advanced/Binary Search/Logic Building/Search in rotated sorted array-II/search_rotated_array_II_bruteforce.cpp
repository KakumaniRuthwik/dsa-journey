#include <bits/stdc++.h>
using namespace std;

// Brute force: Linear scan
bool searchBrute(const vector<int>& nums, int k) {
    for (int x : nums) if (x == k) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k; cin >> k;

    bool found = searchBrute(nums, k);
    cout << (found ? "true\n" : "false\n");
    return 0;
}