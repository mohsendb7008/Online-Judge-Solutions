#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, dp[maxn];
vector<pair<int, int>> adj[maxn];

int sum(int u, int p){
    int ans = 0;
    for(auto v : adj[u])
        if(v.first != p)
            ans += v.second + sum(v.first, u);
    return ans;
}

void dfs(int u, int p, int o){
    dp[u] = dp[p] + (o ? -1 : 1);
    for(auto v : adj[u])
        if(v.first != p)
            dfs(v.first, u, v.second);
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back({v, 0}), adj[v].push_back({u, 1});
    }
    dp[0] = sum(0, -1);
    for(auto v : adj[0])
        dfs(v.first, 0, v.second);
    int ans = *min_element(dp, dp + n);
    cout << ans << endl;
    for(int i = 0; i < n; i++)
        if(dp[i] == ans)
            cout << i + 1 << " ";
    cout << endl;
}