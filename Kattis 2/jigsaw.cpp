#include <iostream>

using namespace std;

long a, b, c;

long sqr(const long x) {
    for (long y = 0; y * y <= x; y++) {
        if (y * y == x)
            return y;
    }
    return -1;
}

int main() {
    cin >> a >> b >> c;
    if (a != 4 || b % 2) {
        cout << "impossible" << endl;
        return 0;
    }
    const long S = b / 2 + 4;
    const long P = a + b + c;
    const long delta = S * S - 4 * P;
    if (delta < 0) {
        cout << "impossible" << endl;
        return 0;
    }
    const long sd = sqr(delta);
    if (sd == -1) {
        cout << "impossible" << endl;
        return 0;
    }
    const long ssw = S + sd;
    const long ssd = S - sd;
    if (ssw < 0 || ssw % 2 || ssd < 0 || ssd % 2) {
        cout << "impossible" << endl;
        return 0;
    }
    const long w = ssw / 2;
    const long h = ssd / 2;
    if (w >= 2 && h >= 2) {
        cout << w << " " << h << endl;
    } else {
        cout << "impossible" << endl;
    }
}