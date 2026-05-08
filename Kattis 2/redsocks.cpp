#include <iostream>

using namespace std;

int main() {
    long p, q;
    while (cin >> p >> q && p + q) {
        if (p == 0) {
            cout << 0 << " " << 2 << endl;
            continue;
        }
        if (p == q) {
            cout << 2 << " " << 0 << endl;
            continue;
        }
        bool found = false;
        for (long r = 1; r <= 50000; r++) {
            const long target = q * r * (r - 1);
            long lo = max(r, 2l);
            long hi = 50000;
            while (lo < hi) {
                const long s = (lo + hi) / 2 + (lo + hi) % 2;
                if (p * s * (s - 1) <= target)
                    lo = s;
                else
                    hi = s - 1;
            }
            if (target == p * lo * (lo - 1)) {
                cout << r << " " << lo - r << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "impossible" << endl;
        }
    }
}