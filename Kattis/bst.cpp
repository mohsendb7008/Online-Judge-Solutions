#include <iostream>
#include <set>

using namespace std;

int h[300001];
set<int> s;

int main() {
    int N;
    unsigned long long int C = 0;
    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        if (s.empty()) {
            h[x] = 0;
        } else {
            auto it = s.upper_bound(x);
            if (it == s.end()) {
                h[x] = h[*prev(it)] + 1;
            } else if (it == s.begin()) {
                h[x] = h[*it] + 1;
            } else {
                h[x] = max(h[*prev(it)], h[*it]) + 1;
            }
        }
        s.insert(x);
        C += h[x];
        cout << C << endl;
    }
}
