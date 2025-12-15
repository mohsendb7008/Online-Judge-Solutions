#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> result;

    for (int k = 2; k <= n; k++) {
        if (n % k != 0) continue;

        int sz = n / k;
        bool ok = true;
        int prev_max = -1;

        for (int i = 0; i < k; i++) {
            int cur_min = INT_MAX;
            int cur_max = INT_MIN;

            for (int j = i * sz; j < (i + 1) * sz; j++) {
                cur_min = min(cur_min, a[j]);
                cur_max = max(cur_max, a[j]);
            }

            if (i > 0 && prev_max >= cur_min) {
                ok = false;
                break;
            }

            prev_max = cur_max;
        }

        if (ok) result.push_back(k);
    }

    if (result.empty()) {
        cout << -1 << "\n";
    } else {
        for (int k : result) cout << k << "\n";
    }

    return 0;
}
