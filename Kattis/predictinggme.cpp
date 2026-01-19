#include <iostream>
using namespace std;

int n, a[1000], dp[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = dp[i + 1];
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                int candidate = a[j] - a[i];
                if (j + 2 < n)
                    candidate += dp[j + 2];
                dp[i] = max(dp[i], candidate);
            }
        }
    }
    cout << dp[0] << endl;
}