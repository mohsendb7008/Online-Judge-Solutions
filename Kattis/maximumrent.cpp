#include <bits/stdc++.h>
using namespace std;

// Maximum Rent

#define num long long int

num a, b, m, s, l;

int main(){
    cin >> a >> b >> m >> s;
    num ans = 0;
    for(num y = 1; y < m; y++){
        l = (s - y) / 2 + (s - y) % 2;
        if(m - y >= max(l , 1ll))
            ans = max(ans, a * (m - y) + b * y);
    }
    cout << ans << endl;
}