#include <bits/stdc++.h>
using namespace std;

// Brute-force: check all numbers from 0 to n
long long floorSqrtBrute(long long n) {
    long long result = 0;
    for (long long i = 0; i <= n; i++) {
        if (i * i <= n) {
            result = i;
        } else {
            break;
        }
    }
    return result;
}

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    cout << floorSqrtBrute(n) << "\n";
    return 0;
}