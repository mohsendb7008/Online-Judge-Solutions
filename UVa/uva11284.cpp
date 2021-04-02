#include <bits/stdc++.h>
using namespace std;

// Shopping Trip

int minf = INT_MIN;
int inf = INT_MAX;

int n, m, p;
int floyd[53][53];
int stores_index[15];
int stores_profit[15];
int dp[15][(1<<12)+3];

int cdp(int i, int mask){
    if(dp[i][mask] != minf)
        return dp[i][mask];
    if((1<<(i-1)) == mask){
        int from_home = floyd[0][stores_index[i]];
        if(from_home == inf)
            return dp[i][mask] = inf;
        return dp[i][mask] = stores_profit[i] - from_home;
    }
    for(int j = 1; j <= p; j++)
        if(j != i && ((1<<(j-1)) & mask)){
            int from_j = cdp(j, mask-(1<<(i-1)));
            int j_to_i = floyd[stores_index[j]][stores_index[i]];
            if(from_j == inf || j_to_i == inf)
                continue;
            dp[i][mask] = max(dp[i][mask], from_j + stores_profit[i] - j_to_i);
        }
    return dp[i][mask] == minf ? inf : dp[i][mask];
}

int main(){
    int t;  
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        n++;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                floyd[i][j] = (i == j ? 0 : inf);
        for(int i = 0; i < m; i++){
            int x, y;
            int w1, w2;
            scanf("%d %d %d.%d", &x, &y, &w1, &w2);
            floyd[x][y] = min(floyd[x][y], w1 * 100 + w2);
            floyd[y][x] = min(floyd[y][x], w1 * 100 + w2);
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(floyd[i][k] != inf && floyd[k][j] != inf)
                        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
        cin >> p;
        int pr1, pr2;
        for(int i = 1; i <= p; i++){
            scanf("%d %d.%d", &stores_index[i], &pr1, &pr2);
            stores_profit[i] = pr1 * 100 + pr2;
        }     
        for(int i = 0; i < 15; i++)
            for(int j = 0; j < (1<<12)+3; j++)
                dp[i][j] = minf;
        int ans = 0;
        for(int i = 1; i <= p; i++)
            for(int j = 0; j < (1<<p); j++)
                if(j & (1<<(i-1))){
                    int subp = cdp(i, j);
                    int to_home = floyd[stores_index[i]][0];
                    if(subp != inf && to_home != inf)
                        ans = max(ans, subp - to_home);
                }
        if(ans > 0)
            printf("Daniel can save $%d.%02d\n", ans/100, ans%100);
        else
            printf("Don't leave the house\n");
    }
}