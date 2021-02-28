#include <bits/stdc++.h>
using namespace std;

// Mafija

const int maxn = 5e5 + 3;

int n, par[maxn], indeg[maxn], vis[maxn], dp[maxn][3], dp2[maxn][3][3];
vector<int> adj[maxn], loop;
queue<int> kahn;

int cdp(int u, int take){
    if(dp[u][take] != -1)
        return dp[u][take];
    int ans = take;
    for(int v : adj[u])
        if(!indeg[v])
            ans += max(cdp(v, 0), take ? 0 : cdp(v, 1));
    return dp[u][take] = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> par[i], par[i]--, indeg[par[i]]++, adj[par[i]].push_back(i);
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            kahn.push(i);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        vis[u] = 1, indeg[par[u]]--;
        if(!indeg[par[u]])
            kahn.push(par[u]);
    }
    for(int i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = -1;
    int ans = 0;
    for(int u = 0; u < n; u++)
        if(!vis[u]){
            loop.clear(), loop.push_back(u), vis[u] = 1;
            int it = par[u];
            while(it != u)
                loop.push_back(it), vis[it] = 1, it = par[it];
            for(int i = loop.size() - 1; i >= 1; i--)
                for(int take = 0; take < 2; take++)
                    for(int first = 0; first < 2; first++){
                        if(i == loop.size() - 1){
                            dp2[i][take][first] = cdp(loop[i], take && !first);
                            continue;
                        }
                        dp2[i][take][first] = cdp(loop[i], take) + max(dp2[i+1][0][first], take ? 0 : dp2[i+1][1][first]);
                    }
            ans += max(cdp(loop[0], 1) + dp2[1][0][1], cdp(loop[0], 0) + max(dp2[1][1][0], dp2[1][0][0]));
        }
    cout << ans << endl;
}