#include <bits/stdc++.h>
using namespace std;

// Tarifa

int main(){
    int x, n, a, ans = 0;
    cin >> x >> n;
    while(n--)
        cin >> a, ans += x-a;
    cout << ans+x << endl;
}