#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

static constexpr double eps = 1e-9;
double water[103];
int idx[103];

inline bool cmp(const int &a, const int &b) {
    return water[a] < water[b];
}

int main() {
    cout << fixed << setprecision(10);
    int k;
    while (cin >> k && k) {
        double b, w, r, c;
        cin >> b >> w >> r >> c;
        water[0] = w;
        for (int i = 1; i < k; i++) {
            water[i] = r;
        }
        iota(idx, idx + k, 0);
        while (b > eps) {
            sort(idx, idx + k, cmp);
            if (water[idx[0]] >= c - eps)
                break;
            const double level = water[idx[0]];
            int ptr = 0;
            while (ptr < k && fabs(water[idx[ptr]] - level) <= eps) {
                ptr++;
            }
            double next = c;
            if (ptr < k) {
                next = water[idx[ptr]];
            }
            const double diff = (next - level) * ptr;
            if (diff <= b + eps) {
                for (int i = 0; i < ptr; i++) {
                    water[idx[i]] = next;
                }
                b -= diff;
            } else {
                for (int i = 0; i < ptr; i++) {
                    water[idx[i]] += b / ptr;
                }
                b = 0.0;
                break;
            }
        }
        cout << k;
        for (int i = 0; i < k; i++)
            cout << " " << water[i] - (i ? r : w);
        cout << endl;
    }
}
