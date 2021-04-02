#include <bits/stdc++.h>
using namespace std;

// Global Warming

int n, m, g[203][203], cc = 0, dp[(1<<22)+3];
vector<int> adj[203];
bool vis[203];
vector<int> cliques[203];

void dfs(int u){
    vis[u] = true;
    cliques[cc].push_back(u);
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    int x, y, w;
    cin >> n >> m;
    while(m--)
        cin >> x >> y >> w, x--, y--, adj[x].push_back(y), adj[y].push_back(x), g[x][y] = w, g[y][x] = w;
    for(int i = 0; i < n; i++)
        if(!vis[i])
            dfs(i), cc++;
    for(int i = 0; i < cc; i++)
        if(cliques[i].size() % 2){
            cout << "impossible" << endl;
            return 0;
        }
    int ans = 0;
    for(int c = 0; c < cc; c++){
        int s = cliques[c].size(), ss = 1 << s;
        for(int mask = 1; mask < ss; mask++){
            dp[mask] = INT_MAX;
            int cp = mask, cnt = 0;
            while(cp){
                if(cp % 2)
                    cnt++;
                cp /= 2;
            }
            if(cnt % 2)
                continue;
            for(int i = 0; i < s; i++)
                if(mask & (1 << i))
                    for(int j = i + 1; j < s; j++)
                        if(mask & (1 << j))
                            dp[mask] = min(dp[mask], g[cliques[c][i]][cliques[c][j]] + dp[mask - (1 << i) - (1 << j)]);
        }
        ans += dp[ss - 1];
    }
    cout << ans << endl;
}