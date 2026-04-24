#include <iostream>
#include <set>

using namespace std;

inline int gcd(const int a, const int b) {
    const int mx = max(abs(a), abs(b));
    const int mi = min(abs(a), abs(b));
    if(mi == 0)
        return mx;
    return gcd(mi, mx % mi);
}

int g, a[300];

inline bool test(const int m) {
    set<int> s;
    for (int i = 0; i < g; i++) {
        int x = a[i] % m;
        if (s.count(x))
            return false;
        s.insert(x);
    }
    return true;
}

int main() {
    cin >> g;
    for (int i = 0; i < g; i++)
        cin >> a[i];
    if (g == 1) {
        cout << 1 << endl;
        return 0;
    }
    set<int> skip;
    for (int i = 0; i < g; i++) {
        for (int j = i + 1; j < g; j++) {
            skip.insert(gcd(a[i], a[j]));
        }
    }
    for (int ans = g; true; ans++) {
        if (skip.count(ans)) {
            continue;
        }
        if (test(ans)) {
            cout << ans << endl;
            break;
        }
    }
}