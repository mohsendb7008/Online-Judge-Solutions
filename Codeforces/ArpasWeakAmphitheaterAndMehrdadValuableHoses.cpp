#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MIN;

int n, m, W, w[1003], b[1003], vis[1003], dp[1003][1003];
vector<int> adj[1003];
vector<vector<int>> groups;

void dfs(int u){
    vis[u] = 1;
    groups.back().push_back(u);
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    cin >> n >> m >> W;
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    while(m--){
        int x, y;
        cin >> x >> y, x--, y--;
        adj[x].push_back(y), adj[y].push_back(x);
    }
    for(int i = 0; i < n; i++)
        if(!vis[i]){
            groups.push_back(vector<int>());
            dfs(i);
        }
    for(int i = groups.size(); i >= 0; i--)
        for(int j = 0; j <= W; j++){
            if(i == groups.size()){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i + 1][j];
            int sum_w = 0, sum_b = 0;
            for(int p : groups[i]){
                if(j + w[p] <= W)
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + w[p]] + b[p]);
                sum_w += w[p], sum_b += b[p];
            }
            if(j + sum_w <= W)
                dp[i][j] = max(dp[i][j], dp[i + 1][j + sum_w] + sum_b);
        }
    cout << dp[0][0] << endl;
}