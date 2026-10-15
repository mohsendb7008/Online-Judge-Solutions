#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    sort(a.rbegin(), a.rend());

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    int ans = 1;
    long long stable = a[0];

    for (int i = 1; i < n; i++) {
        if (pref[i + 1] - pref[ans] >= stable) {
            stable = pref[i + 1];
            ans = i + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
