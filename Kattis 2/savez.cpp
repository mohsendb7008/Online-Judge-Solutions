#include <iostream>
#include <map>
#include "SubstringHash.cpp"

using namespace std;

constexpr long p1 = 31;
constexpr long p2 = 57;
constexpr long mod1 = 1000000007;
constexpr long mod2 = 1000000009;

map<long, int> best;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        string str;
        cin >> str;
        const int m = static_cast<int>(str.size());
        SubstringHash<> hash1(str, p1, mod1, 'A' - 1);
        SubstringHash<> hash2(str, p2, mod2, 'A' - 1);
        int soFar = 1;
        for (int l = 1; l <= m; l++) {
            const long hLeft = hash1.getHash(0, l - 1) * mod1 + hash2.getHash(0, l - 1);
            const long hRight = hash1.getHash(m - l, m - 1) * mod1 + hash2.getHash(m - l, m - 1);
            if (hLeft == hRight && best.count(hLeft)) {
                soFar = max(soFar, best[hLeft] + 1);
            }
        }
        long hash = hash1.getHash(0, m - 1) * mod1 + hash2.getHash(0, m - 1);
        best[hash] = soFar;
        ans = max(ans, soFar);
    }
    cout << ans << endl;
}