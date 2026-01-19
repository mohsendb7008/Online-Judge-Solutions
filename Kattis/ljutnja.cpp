#include <iostream>
using namespace std;

#define ull unsigned long long int

inline ull evenDistribution(const ull total, const ull slots, const ull value) {
    const ull head = total % slots;
    ull headValue = value - (total / slots + 1);
    headValue *= headValue;
    const ull tail = slots - head;
    ull tailValue = value - total / slots;
    tailValue *= tailValue;
    return head * headValue + tail * tailValue;
}

int n;
ull m, a[100000];

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ptr = n-1;
    while (ptr) {
        const ull amount = n - ptr;
        const ull diff = a[ptr] - a[ptr-1];
        if (m >= amount * diff) {
            m -= amount * diff;
            ptr--;
        }
        else {
            ull ans = 0;
            for (int i = 0; i < ptr; i++) {
                ans += a[i] * a[i];
            }
            ans += evenDistribution(m, amount, a[ptr]);
            cout << ans << endl;
            return 0;
        }
    }
    cout << evenDistribution(m, n, a[0]) << endl;
}