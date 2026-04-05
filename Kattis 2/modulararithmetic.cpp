#include <iostream>

using namespace std;

pair<long, pair<long, long>> egcd(const long a, const long b) {
    if (b == 0) {
        return make_pair(a, make_pair(1, 0));
    }
    const auto e = egcd(b, a % b);
    const long g = e.first;
    const long x1 = e.second.first;
    const long y1 = e.second.second;
    const long x2 = y1;
    const long y2 = x1 - a / b * y1;
    return make_pair(g, make_pair(x2, y2));
}

int main() {
    while (true) {
        long n, t;
        cin >> n >> t;
        if (n == 0 && t == 0)
            break;
        while (t--) {
            long x, y, z;
            char op;
            cin >> x >> op >> y;
            if (op == '+') {
                z = ((x + n) % n + (y + n) % n + n) % n;
            } else if (op == '-') {
                z = ((x + n) % n - (y + n) % n + n) % n;
            } else if (op == '*') {
                z = ((x + n) % n * ((y + n) % n) + n) % n;
            } else {
                const auto e = egcd(n, (y + n) % n);
                if (e.first != 1) {
                    z = -1;
                } else {
                    const long yi = e.second.second;
                    z = ((x + n) % n * ((yi + n) % n) + n) % n;
                }
            }
            cout << z << endl;
        }
    }
}