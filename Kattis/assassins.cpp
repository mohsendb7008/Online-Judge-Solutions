#include <iomanip>
#include <iostream>
using namespace std;

int n, m, a[1003], b[1003];
double p[1003], dp[3][32770][18];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> p[i];
        a[i]--;
        b[i]--;
    }
    for (int i = m; i >= 0; i--) {
        for (int mask = 0; mask < 1 << n; mask++) {
            for (int alive = 0; alive < n; alive++) {
                if (i == m) {
                    dp[i % 2][mask][alive] = mask & 1 << alive ? 1 : 0;
                } else {
                    if (mask & 1 << a[i] && mask & 1 << b[i]) {
                        dp[i % 2][mask][alive] =
                            p[i] * dp[1 - i % 2][mask - (1 << b[i])][alive] + (1 - p[i]) * dp[1 - i % 2][mask][alive];
                    }
                    else {
                        dp[i % 2][mask][alive] = dp[1 - i % 2][mask][alive];
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) {
        cout << dp[0][(1 << n) - 1][i] << endl;
    }
}
