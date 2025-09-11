#include <bits/stdc++.h>
using namespace std;

// Function to compute minimum eating speed
int minimumRateToEatBananas(const vector<int>& piles, int h) {
    int maxBananas = *max_element(piles.begin(), piles.end());

    for (int k = 1; k <= maxBananas; k++) {
        long long hours = 0;
        for (int bananas : piles) {
            // ceil(bananas / k) using integer math
            hours += (bananas + k - 1) / k;
            if (hours > h) break; // early stop
        }
        if (hours <= h) return k; // smallest valid speed
    }
    return maxBananas; // fallback
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) cin >> piles[i];

    cout << minimumRateToEatBananas(piles, h) << "\n";
    return 0;
}