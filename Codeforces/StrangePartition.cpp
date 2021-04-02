#include<bits/stdc++.h>
using namespace std;

inline long long int up(long long int k, long long int x){
    return k / x + (k % x ? 1ll : 0ll);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long int x, a;
        cin >> n >> x;
        long long int ans1 = 0, ans2 = 0;
        while(n--)
            cin >> a, ans1 += a, ans2 += up(a, x);
        ans1 = up(ans1, x);
        cout << ans1 << " " << ans2 << endl;
    }
}