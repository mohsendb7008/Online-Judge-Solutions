#include <bits/stdc++.h>
using namespace std;

// Heliocentric

int main(){
    int e, m, test = 1;
    while(cin >> e >> m){
        int ans = 0;
        while(e || m){
            e = (e + 1) % 365;
            m = (m + 1) % 687;
            ans++;
        }
        cout << "Case " << test++ << ": " << ans << endl;
    }
}