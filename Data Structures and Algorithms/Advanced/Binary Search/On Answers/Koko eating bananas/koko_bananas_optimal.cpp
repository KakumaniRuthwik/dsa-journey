#include <bits/stdc++.h>
using namespace std;

/*
 * Optimal binary search solution for Koko Eating Bananas
 * Time Complexity: O(n log max(piles))
 *   - Binary search over possible eating speeds [1 … max(piles)]
 *   - For each speed, compute total hours in O(n)
 * Space Complexity: O(1)
 */

// Calculate total hours needed if Koko eats at speed k
long long hoursNeeded(const vector<int>& piles, int k) {
    long long hours = 0;
    for (int bananas : piles) {
        // ceil(bananas / k) using integer math
        hours += (bananas + k - 1) / k;
    }
    return hours;
}

// Find the minimum eating speed
int minimumRateToEatBananas(const vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (hoursNeeded(piles, mid) <= h) {
            result = mid;     // mid works, try smaller
            high = mid - 1;
        } else {
            low = mid + 1;    // need faster rate
        }
    }
    return result;
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) cin >> piles[i];

    cout << minimumRateToEatBananas(piles, h) << "\n";
    return 0;
}