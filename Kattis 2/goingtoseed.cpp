#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll l = 1, r = n;

    while (l < r) {
        ll L = max(1LL, l - 1);
        ll R = min(n, r + 1);

        ll len = R - L + 1;

        ll a = (len + 3) / 4;
        ll b = (len + 2) / 4;
        ll c = (len + 1) / 4;

        ll x = L + a - 1;
        ll y = x + b;
        ll z = y + c;

        cout << "Q " << L << " " << y
             << " " << x + 1 << " " << z << endl;

        int p, q;
        if (!(cin >> p >> q)) return 0;

        if (p && !q) {
            l = L;
            r = x;
        } else if (p && q) {
            l = x + 1;
            r = y;
        } else if (!p && q) {
            l = y + 1;
            r = z;
        } else {
            l = z + 1;
            r = R;
        }
    }

    cout << "A " << l << endl;
    return 0;
}
