#include <bits/stdc++.h>
using namespace std;

// Exclusively Edible

int n, m, r, c;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> r >> c;
        int ans = r;
        ans = ans ^ (n - 1 - r);
        ans = ans ^ c;
        ans = ans ^ (m - 1 - c);
        cout << (ans ? "Gretel" : "Hansel") << endl;
    }
}