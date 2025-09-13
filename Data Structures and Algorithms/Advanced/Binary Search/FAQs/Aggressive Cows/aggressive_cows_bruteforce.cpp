#include <bits/stdc++.h>
using namespace std;

/*
 * Brute force solution for "Aggressive Cows"
 * Time Complexity: O(n log n + n * (maxDist))
 *   - Sort stalls: O(n log n)
 *   - For each distance from 1 to maxDist, check feasibility in O(n)
 * Space Complexity: O(1)
 */

// Check if we can place at least k cows with minimum distance 'dist'
bool canWePlaceCows(const vector<int>& stalls, int dist, int k) {
    int countCows = 1;              // first cow at stalls[0]
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

// Brute force: try all possible distances from 1 to maxDist
int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int maxDist = stalls.back() - stalls.front();

    for (int d = 1; d <= maxDist; d++) {
        if (!canWePlaceCows(stalls, d, k)) {
            return d - 1; // last feasible distance
        }
    }
    return maxDist; // if all distances up to maxDist work
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) cin >> stalls[i];

    cout << aggressiveCows(stalls, k) << "\n";
    return 0;
}