#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;
const int maxn = 5e4 + 1;
const int maxk = 401;

num dp[maxn][maxk];

int main(){
    for(int j = 1; j < maxk; j++)
        dp[1][j] = 1;
    for(int i = 2; i < maxn; i++){
        for(int j = 1; j < maxk; j++){
            dp[i][j] = dp[i][j - 1];
            if(j < i)
                dp[i][j] = (dp[i][j] + (dp[i - j][maxk - 1] - dp[i - j][max(1, j - 1) - 1] + mod) % mod) % mod;
        }
    }
    int q, x;
    cin >> q;
    while(q--)
        cin >> x, cout << dp[x][maxk - 1] << endl;
}