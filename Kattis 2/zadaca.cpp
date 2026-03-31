#include <iomanip>
#include <iostream>
#include <set>
using namespace std;

multiset<long> a, b, c;

constexpr long mod = 1000000000;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long x;
        cin >> x;
        for (long i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                a.insert(i);
                x = x / i;
            }
        }
        if (x > 1) {
            a.insert(x);
        }
    }
    int m;
    cin >> m;
    while (m--) {
        long x;
        cin >> x;
        for (long i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                b.insert(i);
                x = x / i;
            }
        }
        if (x > 1) {
            b.insert(x);
        }
    }
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
    bool pad = false;
    long ans = 1;
    for (const long i : c) {
        if (ans * i >= mod) {
            pad = true;
        }
        ans = ans * i % mod;
    }
    if (pad) {
        cout << setw(9) << setfill('0');
    }
    cout << ans << endl;
}