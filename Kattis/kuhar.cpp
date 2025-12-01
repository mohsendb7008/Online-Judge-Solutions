#include <bits/stdc++.h>
using namespace std;

int N, M;
int X[105], Y[105], S1[105], P1[105], S2[105], P2[105];

bool can(long long k) {
    long long cost = 0;
    for (int i = 0; i < N; i++) {
        long long need = k * X[i];
        if (need <= Y[i]) continue;
        long long missing = need - Y[i];
        long long best = LLONG_MAX;
        long long maxLarge = (missing + S2[i] - 1) / S2[i];
        for (long long largeCnt = 0; largeCnt <= maxLarge; largeCnt++) {
            long long covered = largeCnt * S2[i];
            long long remain = max(0LL, missing - covered);
            long long smallCnt = (remain + S1[i] - 1) / S1[i];
            long long c = largeCnt * P2[i] + smallCnt * P1[i];
            if (c < best) best = c;
            if (covered >= missing) break;
        }
        if (best == LLONG_MAX) return false;
        cost += best;
        if (cost > M) return false;
    }
    return cost <= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> S1[i] >> P1[i] >> S2[i] >> P2[i];
    }

    long long low = 0, high = 100000;
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if (can(mid)) low = mid;
        else high = mid - 1;
    }

    cout << low << "\n";
    return 0;
}
