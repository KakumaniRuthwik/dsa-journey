#include <bits/stdc++.h>
using namespace std;

/*
 * Optimal solution for "Aggressive Cows" using Binary Search on Answer (BSOA)
 * Time Complexity: O(n log n + n log(maxDist))
 *   - Sort stalls: O(n log n)
 *   - Binary search over distance: O(log(maxDist))
 *   - Each feasibility check: O(n)
 * Space Complexity: O(1)
 */

// Check if we can place at least k cows with minimum distance 'dist'
bool canWePlaceCows(const vector<int>& stalls, int dist, int k) {
    int countCows = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            countCows++;
            lastPos = stalls[i];
            if (countCows >= k) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls.back() - stalls.front();
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canWePlaceCows(stalls, mid, k)) {
            result = mid;     // feasible, try larger distance
            low = mid + 1;
        } else {
            high = mid - 1;   // not feasible, try smaller distance
        }
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) cin >> stalls[i];

    cout << aggressiveCows(stalls, k) << "\n";
    return 0;
}