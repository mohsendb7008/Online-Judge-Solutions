#include<bits/stdc++.h>
using namespace std;

// Camp Lunches

int n, s[1000], k, x, a, b;
bool dp[10001];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    cin >> k >> x >> a >> b;
    dp[0] = 1;
    for(int i = 0; i < n; i++)
        for(int w = b; w >= 0; w--)
            if(dp[w] && w + s[i] <= b)
                dp[w + s[i]] = 1;
    for(int ans = b; ans >= a; ans--)
        if(dp[ans] && !(ans % x) && ans / x <= k){
            cout << ans << endl;
            return 0;
        }
    cout << "impossible" << endl;
}