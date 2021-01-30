#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;

int n, k, a[1003], ps[1003];
num dp[1003][1003];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a, a + n + 1);
        partial_sum(a, a + n + 1, ps);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= i; j++){
                if(!j || i == j)
                    dp[i][j] = 1;
                else{
                    dp[i][j] = dp[i-1][j-1];
                    if(ps[i] - ps[i-j] == ps[i-1] - ps[i-1-j])
                        dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
                }
            }
        cout << dp[n][k] << endl;
    }
}