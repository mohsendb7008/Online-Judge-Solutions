#include <iostream>
#include <set>
#include "SubstringHash.cpp"

using namespace std;

int n, m;
char g[1000][1000];
long h[1000][1000];
constexpr long p1 = 31;
constexpr long p2 = 57;
constexpr long mod1 = 1000000007;
constexpr long mod2 = 1000000009;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        string col = "";
        for (int j = 0; j < n; j++) {
            col.push_back(g[j][i]);
        }
        SubstringHash<> hash1(col, p1, mod1, 'a');
        SubstringHash<> hash2(col, p2, mod2, 'a');
        for (int j = 0; j < n; j++) {
            h[j][i] = hash1.getHash(j, n - 1) * mod1 + hash2.getHash(j, n - 1);
        }
    }
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        const int mid = (lo + hi) / 2 + (lo + hi) % 2;
        set<long> s;
        for (int i = 0; i < m; i++) {
            s.insert(h[mid][i]);
        }
        if (s.size() == m) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
}
