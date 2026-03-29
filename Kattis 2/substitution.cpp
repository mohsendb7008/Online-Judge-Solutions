#include <iostream>
#include <vector>

using namespace std;

inline int gcd(const int a, const int b) {
    const int mx = max(abs(a), abs(b));
    const int mi = min(abs(a), abs(b));
    if(mi == 0)
        return mx;
    return gcd(mi, mx % mi);
}

inline int lcm(const int a, const int b) {
    return a * b / gcd(a, b);
}

inline int chinese_remainder(const vector<pair<int, int>>& v) {
    if (v.empty())
        return 0;
    int l = v[0].first;
    int k = v[0].second;
    for (int i = 1; i < v.size(); i++) {
        while (k % v[i].first != v[i].second)
            k += l;
        l = lcm(l, v[i].first);
    }
    return k;
}

int n, m[203], c[203], p[103];
vector<pair<int, int>> v;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> m[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 1; i <= 100; i++)
            cin >> p[i];
        v.clear();
        for (int i = 0; i < n; i++) {
            if (p[m[i]] == m[i])
                continue;
            int x = p[m[i]];
            int a = 1;
            while (x != m[i]) {
                x = p[x];
                a++;
            }
            int y = m[i];
            int b = 0;
            while (y != c[i]) {
                y = p[y];
                b++;
            }
            v.emplace_back(a, b);
        }
        cout << chinese_remainder(v) << endl;
    }
}