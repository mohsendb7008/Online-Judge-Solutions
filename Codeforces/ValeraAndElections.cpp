#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, par[maxn], col[maxn], dp[maxn];
vector<pair<int, int>> adj[maxn];
vector<int> ans;

void dfs(int u, int p, int c){
    par[u] = p, col[u] = c, dp[u] = 0;
    for(auto v : adj[u])
        if(v.first != p){
            dfs(v.first, u, v.second);
            dp[u] += dp[v.first] + v.second-1;
        }
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        adj[u].push_back({v, w}), adj[v].push_back({u, w});
    }
    dfs(0, -1, 0);
    for(int i = 0; i < n; i++)
        if(col[i] == 2 && dp[i] == 0)
            ans.push_back(i);
    cout << ans.size() << '\n';
    for(int i : ans)
        cout << i+1 << ' ';
    cout << '\n';
}