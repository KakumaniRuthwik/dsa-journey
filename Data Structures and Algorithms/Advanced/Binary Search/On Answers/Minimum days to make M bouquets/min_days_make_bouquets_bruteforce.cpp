#include <bits/stdc++.h>
using namespace std;

/*
 * Brute force solution for "Minimum Days to Make M Bouquets"
 * Time Complexity: O((maxDay - minDay + 1) * n)
 *   - Iterate over each day in [min(nums) … max(nums)]
 *   - For each day, check feasibility in O(n)
 * Space Complexity: O(1)
 */

// Check if it's possible to make at least m bouquets on a given day
bool canMakeBouquets(const vector<int>& nums, int day, int m, int k) {
    int count = 0, bouquets = 0;
    for (int bloomDay : nums) {
        if (bloomDay <= day) {
            count++;
            if (count == k) {
                bouquets++;
                count = 0;
            }
        } else {
            count = 0; // reset streak
        }
    }
    return bouquets >= m;
}

int roseGarden(int n, const vector<int>& nums, int k, int m) {
    // Not enough flowers to make m bouquets
    if ((long long)k * m > n) return -1;

    int minDay = *min_element(nums.begin(), nums.end());
    int maxDay = *max_element(nums.begin(), nums.end());

    for (int day = minDay; day <= maxDay; day++) {
        if (canMakeBouquets(nums, day, m, k)) return day;
    }
    return -1;
}

int main() {
    int n, m, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> k >> m;

    cout << roseGarden(n, nums, k, m) << "\n";
    return 0;
}