#include <bits/stdc++.h>
using namespace std;

// Compute base^exp with early stop if it exceeds 'limit' (to avoid overflow)
long long powerWithLimit(long long base, int exp, long long limit) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
        if (result > limit) return result; // early exit
    }
    return result;
}

// Binary search the answer in [1..M]
int nthRootOptimal(int N, long long M) {
    if (M == 1) return 1; // 1^N = 1

    long long low = 1, high = M;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long val = powerWithLimit(mid, N, M);

        if (val == M) return (int)mid;
        if (val > M)  high = mid - 1;
        else          low  = mid + 1;
    }
    return -1; // no integer Nth root
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; long long M;
    if (!(cin >> N >> M)) return 0;

    cout << nthRootOptimal(N, M) << "\n";
    return 0;
}