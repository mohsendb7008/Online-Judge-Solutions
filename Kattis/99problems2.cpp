#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    multiset<long long> s;
    for(int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        s.insert(x);
    }

    while(M--) {
        int q;
        long long x;
        cin >> q >> x;

        if(q == 1) {
            auto it = s.upper_bound(x);
            if(it == s.end()) {
                cout << -1 << "\n";
            } else {
                cout << *it << "\n";
                s.erase(it);
            }
        } else {
            auto it = s.upper_bound(x);
            if(it == s.begin()) {
                cout << -1 << "\n";
            } else {
                --it;
                cout << *it << "\n";
                s.erase(it);
            }
        }
    }
}
