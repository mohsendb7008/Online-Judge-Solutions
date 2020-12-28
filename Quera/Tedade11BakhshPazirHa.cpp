#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;

const int maxn = 1e5 + 3;

num dp[maxn][13][3];

int main(){
    int k;
    cin >> k;
    for(int n = 0; n <= k; n++)
        for(int m = 0; m < 11; m++)
            for(int b = 0; b <= 1; b++){
                if(!n){
                    dp[n][m][b] = !m;
                    continue;
                }
                for(int d = 0; d < 10; d++){
                    if(d == 3 || d == 5 || d == 7)
                        continue;
                    dp[n][m][b] = (dp[n][m][b] + dp[n-1][b ? ((m + d) % 11) : ((m - d + 11) % 11)][!b]) % mod;
                }
            }
    cout << dp[k][0][0] << endl;
}