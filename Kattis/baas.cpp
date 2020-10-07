#include <bits/stdc++.h>
using namespace std;

// BAAS

const int maxn = 1e5 + 3;

int n, a[maxn], dp[maxn];
vector<int> adj[maxn];

int cdp(int u){
    if(dp[u] != -1)
        return dp[u];
    int ans = a[u];
    for(int v : adj[u])
        ans = max(ans, a[u] + cdp(v));
    return dp[u] = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        int m, x;
        cin >> m;
        while(m--)
            cin >> x, adj[x-1].push_back(i);
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int save = a[i];
        a[i] = 0;
        fill_n(dp, n, -1);
        ans = min(ans, cdp(0));
        a[i] = save;
    }
    cout << ans << endl;
}