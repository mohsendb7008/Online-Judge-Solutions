#include <iostream>
#include <cmath>
using namespace std;

int n;
double v, x[18], y[18], dawn[18], dis[18][18], dp[(1 << 17) + 1][18][18];

inline double t(const int e, const int i, const int j = -1) {
    return dis[i][j == -1 ? n : j] * (1 << e) / v;
}

#define invalid 75000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        cin >> n >> v;
        if (!n)
            break;
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        x[n] = y[n] = 0;
        for (int i = 0; i < n; i++)
            dawn[i] = 60 * 720 + 3 * x[i] / 100;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                const double dx = x[i] - x[j];
                const double dy = y[i] - y[j];
                dis[i][j] = sqrt(dx * dx + dy * dy);
            }
        }
        for (int mask = 0; mask < 1 << n; mask++) {
            for (int i = 0; i <= n; i++) {
                for (int k = 0; k <= n; k++) {
                    dp[mask][i][k] = invalid;
                }
            }
        }
        dp[0][n][0] = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            const int k = __builtin_popcount(mask);
            double loop = invalid;
            for (int e = 0; e <= n-k; e++)
                loop = min(loop, dp[mask][n][e]);
            for (int i = 0; i < n; i++) {
                if (!(mask & 1 << i))
                    continue;
                if (dp[mask][i][0] == invalid)
                    continue;
                loop = min(loop, dp[mask][i][0] + t(0, i));
            }
            if (loop != invalid)
                for (int e = 0; e <= n-k; e++)
                    dp[mask][n][e] = min(dp[mask][n][e], loop);
            for (int i = 0; i <= n; i++) {
                if (i < n && !(mask & 1 << i))
                    continue;
                for (int e = 1; e <= n-k; e++) {
                    if (dp[mask][i][e] == invalid)
                        continue;
                    for (int j = 0; j < n; j++) {
                        if (!(mask & 1 << j)) {
                            const double ti = dp[mask][i][e] + t(e, i, j);
                            if (ti < dawn[j]) {
                                const int next = mask + (1 << j);
                                dp[next][j][e - 1] = min(dp[next][j][e - 1], ti);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int mask = 0; mask < 1 << n; mask++)
            for (int i = 0; i <= n; i++)
                if (dp[mask][i][0] != invalid)
                    ans = max(ans, __builtin_popcount(mask));
        cout << ans << "\n";
    }
}