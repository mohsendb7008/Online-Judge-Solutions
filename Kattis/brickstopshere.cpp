#include <iostream>
#include <climits>
using namespace std;

int n, con[251], price[251], dp[2][51][50001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> con[i] >> price[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 50; j++) {
            for (int k = 0; k <= 50000; k++) {
                dp[i % 2][j][k] = numeric_limits<int>::max();
                if (i) {
                    dp[i % 2][j][k] = dp[1 - i % 2][j][k];
                    if (j && k >= con[i-1] && dp[1 - i % 2][j - 1][k - con[i-1]] != numeric_limits<int>::max()) {
                        dp[i % 2][j][k]= min(dp[i % 2][j][k], dp[1 - i % 2][j - 1][k - con[i-1]] + price[i-1]);
                    }
                } else {
                    if (!j && !k) {
                        dp[i % 2][j][k] = 0;
                    }
                }
            }
        }
    }
    int c;
    cin >> c;
    while (c--) {
        int m, c1, c2;
        cin >> m >> c1 >> c2;
        c1 *= m;
        c2 *= m;
        int best = numeric_limits<int>::max();
        for (int i = c1; i <= c2; i++) {
            best = min(best, dp[n % 2][m][i]);
        }
        if (best == numeric_limits<int>::max()) {
            cout << "impossible" << endl;
        }
        else {
            cout << best << endl;
        }
    }
}