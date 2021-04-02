#include <bits/stdc++.h>
using namespace std;

// Transit Woes

int s, t, n, d[1003], b[1003], c[1003];

int main(){
    cin >> s >> t >> n;
    for(int i = 0; i <= n; i++)
        cin >> d[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++){
        s += d[i];
        if(s % c[i])
            s += c[i] - s % c[i];
        s += b[i];
    }
    s += d[n];
    cout << (s <= t ? "yes" : "no") << endl;
}