#include<bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;
const int maxn = (1 << 16);

int n, a[maxn], z = 0, card[maxn], dp[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(!a[i])
            z++;
    }
    if(z){
        cout << n - z << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        int mask = maxn - 1 - a[i];
        int it = mask;
        while(it)
            card[it] = 1, it = (it - 1) & mask;
    }
    dp[0] = 0;
    for(int mask = 1; mask < maxn; mask++){
        dp[mask] = inf;
        int sub = mask;
        while(sub){
            if(card[sub] && dp[mask - sub] != inf)
                dp[mask] = min(dp[mask], dp[mask - sub] + 1);
            sub = (sub - 1) & mask;
        }
    }
    cout << dp[maxn - 1] + n - 2 << endl;
}