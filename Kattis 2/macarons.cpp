#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000000;

using Matrix = vector<vector<ll>>;

Matrix multiply(const Matrix& a, const Matrix& b) {
    int n = a.size();
    Matrix c(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (a[i][k] == 0) continue;

            for (int j = 0; j < n; j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return c;
}

Matrix power(Matrix a, ll p) {
    int n = a.size();
    Matrix res(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }

    while (p > 0) {
        if (p & 1) res = multiply(res, a);
        a = multiply(a, a);
        p >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin >> n >> m;

    int s = 1 << n;
    Matrix t(s, vector<ll>(s));

    auto dfs = [&](auto&& self, int row, int mask, int next) -> void {
        if (row == n) {
            t[mask][next]++;
            return;
        }

        if (mask & (1 << row)) {
            self(self, row + 1, mask, next);
            return;
        }

        self(self, row + 1, mask, next);
        self(self, row + 1, mask, next | (1 << row));

        if (row + 1 < n && !(mask & (1 << (row + 1)))) {
            self(self, row + 2, mask, next);
        }
    };

    for (int mask = 0; mask < s; mask++) {
        dfs(dfs, 0, mask, 0);
    }

    Matrix ans = power(t, m);
    cout << ans[0][0] << '\n';

    return 0;
}
