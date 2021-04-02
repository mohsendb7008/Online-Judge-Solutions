#include <bits/stdc++.h>
using namespace std;

// Programming Team

#define EPS 1e-9

const int maxn = 2503;
const double inf = LLONG_MIN;

int k, n, par[maxn], cnt = 0, preorder[maxn], nexty[maxn];
double s[maxn], p[maxn], dp[maxn][maxn];
vector<int> adj[maxn];

void dfs(int u){
    int save = cnt;
    preorder[cnt++] = u;
    for(int v : adj[u])
        dfs(v);
    nexty[save] = cnt;
}

int main(){
    cin >> k >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i] >> p[i] >> par[i], par[i]--;
        if(par[i] != -1)
            adj[par[i]].push_back(i);
    }
    for(int i = 0; i < n; i++)
        if(par[i] == -1)
            dfs(i);
    double lo = 0, hi = 10000;
    while(fabs(hi - lo) > EPS){ 
        double mid = (lo + hi) / 2;
        for(int i = n; i >= 0; i--)
            for(int j = 0; j <= k; j++){
                if(i == n)
                    dp[i][j] = j ? inf : 0;
                else{
                    dp[i][j] = dp[nexty[i]][j];
                    if(j && dp[i+1][j-1] != inf)
                        dp[i][j] = max(dp[i][j], dp[i+1][j-1] + p[preorder[i]] - mid * s[preorder[i]]);
                }
            }
        if(dp[0][k] > 0)
            lo = mid;
        else
            hi = mid;
    }
    cout << fixed << setprecision(3) << lo + EPS << endl;
}