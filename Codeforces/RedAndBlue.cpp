#include <bits/stdc++.h>
using namespace std;

int n, m, r[103], b[103], psr[103], psb[103], dp[103][103];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> r[i];
        cin >> m;
        for(int i = 1; i <= m; i++)
            cin >> b[i];
        partial_sum(r, r + n + 1, psr);
        partial_sum(b, b + m + 1, psb);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++){
                if(!i && !j)
                    dp[i][j] = 0;
                else if(!i)
                    dp[i][j] = max(psr[i] + psb[j], dp[i][j - 1]);
                else if(!j)
                    dp[i][j] = max(psr[i] + psb[j], dp[i - 1][j]);
                else
                    dp[i][j] = max(psr[i] + psb[j], max(dp[i - 1][j], dp[i][j - 1]));
            }
        cout << dp[n][m] << endl;
    }
}
