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

// Brute force: try all candidates i = 1..M
int nthRootBrute(int N, long long M) {
    if (M == 1) return 1; // 1^N = 1

    for (long long i = 1; i <= M; i++) {
        long long val = powerWithLimit(i, N, M);
        if (val == M) return (int)i;
        if (val > M) break; // no need to continue, values will only increase
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; long long M;
    if (!(cin >> N >> M)) return 0;

    cout << nthRootBrute(N, M) << "\n";
    return 0;
}