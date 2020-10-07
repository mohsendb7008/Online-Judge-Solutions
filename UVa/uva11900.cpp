#include <bits/stdc++.h>
using namespace std;

// Boiled Eggs

int t, n, p, q, eggs[33], psum[33], ans;

int main(){
    cin >> t;
    for(int c = 1; c <= t; c++){
        cin >> n >> p >> q;
        for(int i = 0; i < n; i++)
            cin >> eggs[i];
        sort(eggs, eggs+n);
        partial_sum(eggs, eggs+n, psum);
        ans = min(n-1, p-1);
        while(ans >= 0 && psum[ans] > q)
            ans--;
        cout << "Case " << c << ": " << ans + 1 << endl;
    }
}