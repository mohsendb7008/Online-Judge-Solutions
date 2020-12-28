#include <bits/stdc++.h>
using namespace std;

int n, k, a[5003], s[5003], e[5003];
int mi = INT_MAX, ma = INT_MIN;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i], mi = min(mi, a[i]), ma = max(ma, a[i]);
    if(k >= 3){
        cout << mi << endl;
        return 0;
    }
    if(k == 1){
        cout << ma << endl;
        return 0;
    }
    s[0] = a[0];
    for(int i = 1; i < n; i++)
        s[i] = max(s[i-1], a[i]);
    e[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)
        e[i] = max(e[i+1], a[i]);
    int ans = INT_MAX;
    for(int i = 0; i < n-1; i++)
        ans = min(ans, min(s[i], e[i+1]));
    cout << ans << endl;
}