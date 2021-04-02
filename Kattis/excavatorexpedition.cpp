#include <bits/stdc++.h>
using namespace std;

// Excavator Expedition

const int maxn = 4e5 + 3;

#define inf INT_MIN

int n, m, dp[maxn];
char s[maxn];
vector<int> adj[maxn];

int cdp(int u){
    if(dp[u] != -1)
        return dp[u];
    int ans = inf;
    int c = 0;
    if(u != 0)
        c = s[u] == 'X' ? 1 : -1;
    for(int v : adj[u]){
        int subp = cdp(v);
        if(subp != inf)
            ans = max(ans, c + subp);
    } 
    return dp[u] = ans;
}

int main(){
    cin >> n >> m >> s;
    int u, v;
    while(m--)
        cin >> u >> v, adj[u].push_back(v);
    fill_n(dp, n, -1);
    dp[n-1] = 0;
    cout << cdp(0) << endl;
}