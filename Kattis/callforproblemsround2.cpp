#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    unordered_set<long long> s;
    while(n--) {
        long long x;
        cin >> x;
        s.insert(x);
    }
    cout << min((int)s.size(), k) << "\n";
    return 0;
}
