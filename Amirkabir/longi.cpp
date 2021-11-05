#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

const int maxn = 1e5 + 3;

int n, a[maxn];
vector<int> adj[maxn];

long long int dp[maxn];

void dfs(int u, int p){
    dp[u] = a[u] == 6;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            dp[u] = (dp[u] * (1 + dp[v])) % mod;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0, -1);
    long long int ans = 0;
    for(int i = 0; i < n; i++)
        ans = (ans + dp[i]) % mod;
    cout << ans << endl;
}