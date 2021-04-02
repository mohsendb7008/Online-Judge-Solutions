#include <bits/stdc++.h>
using namespace std;

// Commemorative Race

const int maxn = 2e5 + 3;

int n, m;
vector<int> adj[maxn];

int dp[maxn];

int cdp(int u){
    if(dp[u] != -1)
        return dp[u];
    dp[u] = 0;
    for(int v : adj[u])
        dp[u] = max(dp[u], 1 + cdp(v));
    return dp[u];
}

bool vis[maxn];
int cnt[maxn];

void build(int u){
    vis[u] = true;
    cnt[dp[u]]++;
    for(int v : adj[u])
        if(dp[v] + 1 == dp[u] && !vis[v])
			build(v);
}

vector<int> tmp;

int main(){
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, adj[x-1].push_back(y-1);
    fill_n(dp, n, -1);
    int lp = INT_MIN;
    for(int i = 0; i < n; i++)
        lp = max(lp, cdp(i));
    for(int i = 0; i < n; i++)
        if(dp[i] == lp && !vis[i])
            build(i);
    int ans = lp;
    for(int u = 0; u < n; u++)
        if(!adj[u].empty() && vis[u] && cnt[dp[u]] == 1){
            int p = lp - dp[u];
            if(adj[u].size() == 1)
                ans = min(ans, p);
            else{
                tmp.clear();
                for(int v : adj[u])
                    tmp.push_back(dp[v]);
                sort(tmp.begin(), tmp.end());
                ans = min(ans, p + 1 + tmp[tmp.size() - 2]);
            }
        }
    cout << ans << endl;   
}