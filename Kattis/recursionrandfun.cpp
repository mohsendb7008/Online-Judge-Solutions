#include <bits/stdc++.h>
using namespace std;

bool dp[105][10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, i, k;
    while (cin >> a >> b >> c >> i >> k) {
        memset(dp, 0, sizeof(dp));
        if (k >= 1) dp[0][1] = true;

        for (int idx = 1; idx <= i; idx++) {
            for (int val = 1; val <= k; val++) {
                for (int x = 0; x < b; x++) {
                    int need = val - a - x;
                    if (need < 1) continue;
                    for (int y = 0; y < c; y++) {
                        int prev = idx - 1 - y;
                        if (prev < 0) prev = 0;
                        if (dp[prev][need]) {
                            dp[idx][val] = true;
                            goto next_value;
                        }
                    }
                }
            next_value:;
            }
        }

        cout << (dp[i][k] ? "possible" : "impossible") << "\n";
    }
}
