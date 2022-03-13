// Social running

#include <bits/stdc++.h>
using namespace std;

int n, a[13];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
        ans = min(ans, a[i] + a[(i + 2) % n]);
    cout << ans << endl;
}
