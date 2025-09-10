#include <bits/stdc++.h>
using namespace std;

// Optimal: Binary search to compute floor of square root
long long floorSqrtOptimal(long long n) {
    long long low = 1, high = n, result = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // Check without overflow: mid <= n / mid
        if (mid <= n / mid) {
            result = mid;       // valid candidate
            low = mid + 1;      // search right
        } else {
            high = mid - 1;     // search left
        }
    }
    return result;
}

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    cout << floorSqrtOptimal(n) << "\n";
    return 0;
}