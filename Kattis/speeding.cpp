#include <bits/stdc++.h>
using namespace std;

// Speeding

int n, t[103], d[103];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i] >> d[i];
    int ans = 0;
    for(int i = 1; i < n; i++)
        ans = max(ans, (d[i] - d[i-1]) / (t[i] - t[i-1]));
    cout << ans << endl;
}