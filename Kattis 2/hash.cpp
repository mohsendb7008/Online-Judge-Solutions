#include <iostream>
using namespace std;

int normalize(int x, const int mod) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

int egcd(const int a, const int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    const int g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return g;
}

int inverse(const int a, const int mod) {
    int x, y;
    const int g = egcd(mod, normalize(a, mod), x, y);
    return g == 1 ? normalize(y, mod) : -1;
}

int n, k, m, lg[6][1 << 25], rg[6][1 << 25];

int main() {
    cin >> n >> k >> m;
    m = 1 << m;
    lg[0][0] = 1;
    for (int i = 1; i <= 5; i++) {
        for (int f = 0; f < m; f++) {
            if (!lg[i-1][f])
                continue;
            for (int a = 1; a <= 26; a++) {
                lg[i][f * 33 & m - 1 ^ a] += lg[i-1][f];
            }
        }
    }
    if (n <= 5) {
        cout << lg[n][k] << endl;
        return 0;
    }
    const int inv33 = inverse(33, m);
    rg[0][k] = 1;
    for (int i = 1; i <= 5; i++) {
        for (int f = 0; f < m; f++) {
            if (!rg[i-1][f])
                continue;
            for (int a = 1; a <= 26; a++) {
                rg[i][(f ^ a) * inv33 & m - 1] += rg[i-1][f];
            }
        }
    }
    int ans = 0;
    for (int f = 0; f < m; f++) {
        ans += lg[n / 2 + n % 2][f] * rg[n / 2][f];
    }
    cout << ans << endl;
}