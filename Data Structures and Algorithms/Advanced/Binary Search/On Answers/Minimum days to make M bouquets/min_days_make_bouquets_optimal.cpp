#include <bits/stdc++.h>
using namespace std;

/*
 * Optimal binary search solution for "Minimum Days to Make M Bouquets"
 * Time Complexity: O(n log maxDay)
 *   - Binary search over possible days [min(nums) … max(nums)]
 *   - Each feasibility check runs in O(n)
 * Space Complexity: O(1)
 */

// Check if it's possible to make at least m bouquets by 'day'
bool canMakeBouquets(const vector<int>& nums, int day, int k, int m) {
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
    if ((long long)m * k > n) return -1; // not enough flowers

    int low = *min_element(nums.begin(), nums.end());
    int high = *max_element(nums.begin(), nums.end());
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canMakeBouquets(nums, mid, k, m)) {
            result = mid;   // feasible, try earlier day
            high = mid - 1;
        } else {
            low = mid + 1;  // need more days
        }
    }
    return result;
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