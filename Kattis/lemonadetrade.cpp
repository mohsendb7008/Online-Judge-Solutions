#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<string, double> rate;

int main() {
    rate["pink"] = 0;
    int n;
    cin >> n;
    while (n--) {
        string o, w;
        double r;
        cin >> o >> w >> r;
        r = log10(r);
        if (rate.find(w) != rate.end()) {
            if (rate.find(o) == rate.end()) {
                rate[o] = rate[w] + r;
            }
            else {
                rate[o] = max(rate[o], rate[w] + r);
            }
        }
    }
    double ans = 0;
    if (rate.find("blue") != rate.end()) {
        const double p = rate["blue"];
        if (p >= 1.0 - 1e-9) {
            ans = 10.0;
        } else {
            ans = pow(10.0, p);
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}