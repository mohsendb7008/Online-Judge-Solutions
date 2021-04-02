#include <bits/stdc++.h>
using namespace std;

int n, k, dp[2][501][501];
char s[501];

int main(){
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    k = min(n, k);
    for(int rows = 0; rows <= n; rows++)
        for(int items = 0; items <= n; items++)
            for(int p = 0; p <= k ; p++){
                if(!rows){
                    dp[rows % 2][items][p] = 0;
                    continue;
                }
                if(s[rows-1] == 'K'){
                    dp[rows % 2][items][p] = rows * items + dp[(rows + 1) % 2][1][p];
                    continue;
                }
                dp[rows % 2][items][p] = dp[(rows + 1) % 2][items+1][p];
                if(p)
                    dp[rows % 2][items][p] = max(dp[rows % 2][items][p], rows * items + dp[(rows + 1) % 2][1][p-1]);
            }
    printf("%d\n", dp[n % 2][1][k]);
}