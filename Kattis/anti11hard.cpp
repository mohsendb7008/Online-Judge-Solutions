#include <bits/stdc++.h>
using namespace std;

// Ocean's Anti-11 (Hard)

int t, n, b, m, h;
const int mod = 1e9+7;
string tmp;
long long int dp[10003][(1<<10)+3];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> tmp;
        b = tmp.size(), m = 0, h = (1<<(b-1))-1;
        for(char c : tmp)
            m = (m<<1) + c - '0';
        for(int i = n; i >= 0; i--)
            for(int mask = 0; mask < (1<<b); mask++){
                if(i >= b && mask == m)
                    dp[i][mask] = 0;
                else if(i == n)
                    dp[i][mask] = 1;
                else if(i >= b)
                    dp[i][mask] = (dp[i+1][(mask&h)<<1] + dp[i+1][((mask&h)<<1)+1]) % mod;
                else
                    dp[i][mask] = (dp[i+1][mask<<1] + dp[i+1][(mask<<1)+1]) % mod;
            }
        cout << dp[0][0] << endl;
    }
}