#include <iostream>
#include <map>
using namespace std;

int n, w[1503][1503], dp[1503][1503];

int cdp(const int l, const int r) {
    const int k = max(l, r) + 1;
    if (k == n)
        return 0;
    if (dp[l][r] != numeric_limits<int>::max())
        return dp[l][r];
    return dp[l][r] = min(w[k][l] + cdp(k, r), cdp(l, k) + w[k][r]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
            dp[i][j] = numeric_limits<int>::max();
        }
    }
    cout << cdp(0, 0) << endl;
}

