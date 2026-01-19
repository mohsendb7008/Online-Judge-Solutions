#include <iostream>
#include <iomanip>
using namespace std;

int paid[1000], share[1000];

int main() {
    int n;
    while (cin >> n) {
        if (!n)
            break;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int dollars, cents;
            char dummy;
            cin >> dollars >> dummy >> cents;
            paid[i] = dollars * 100 + cents;
            sum += paid[i];
        }
        sort(paid, paid + n);
        int avg = sum / n;
        for (int i = 0; i < n; i++) {
            share[i] = avg;
        }
        for (int i = 0; i < sum % n; i++) {
            share[n - i - 1]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (paid[i] > share[i]) {
                ans += paid[i] - share[i];
            }
        }
        cout << '$' << ans / 100 << '.' << (ans % 100 < 10 ? "0" : "") << ans % 100 << endl;
    }
}