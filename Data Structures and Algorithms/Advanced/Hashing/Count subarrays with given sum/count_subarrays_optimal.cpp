#include <bits/stdc++.h>
using namespace std;

int countSubarraysOptimal(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // base case
    int sum = 0, count = 0;

    for (int num : nums) {
        sum += num;
        if (prefixCount.find(sum - k) != prefixCount.end()) {
            count += prefixCount[sum - k];
        }
        prefixCount[sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << countSubarraysOptimal(nums, k) << endl;
    return 0;
}