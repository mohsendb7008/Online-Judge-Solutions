#include <bits/stdc++.h>
using namespace std;

int n, u, v, a[103];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> u >> v;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 1;
        for(int i = 1; i < n; i++)
            if(abs(a[i]-a[i-1]) >= 2){
                ans = 0;
                break;
            }
        if(ans)
            ans = (all_of(a, a+n, [](int& x){return x==a[0];}) ? min(u+v, 2*v) : min(u, v));
        cout << ans << endl;
    }
}