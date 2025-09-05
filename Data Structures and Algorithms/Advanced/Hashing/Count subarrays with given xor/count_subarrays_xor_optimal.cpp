#include <bits/stdc++.h>
using namespace std;

int countSubarraysXorOptimal(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int xr = 0, count = 0;
    freq[0] = 1; // base case

    for (int num : nums) {
        xr ^= num;

        int target = xr ^ k;
        if (freq.find(target) != freq.end()) {
            count += freq[target];
        }

        freq[xr]++;
    }
    return count;
}

int main() {
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    cout << countSubarraysXorOptimal(nums, k) << endl;
    return 0;
}