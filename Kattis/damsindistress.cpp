#include <bits/stdc++.h>
using namespace std;

// Dams in Distress

#define num long long int

const int maxn = 2e5 + 3;

int n;
num c[maxn], w[maxn];
vector<int> adj[maxn];

num ans = LLONG_MAX;

void dfs(int u, num r){
    ans = min(ans, max(c[u] - w[u], r - w[u]));
    for(int v : adj[u])
        dfs(v, max(c[u] - w[u], r - w[u]));
}

int main(){
    cin >> n >> c[0];
    int p;
    for(int i = 1; i <= n; i++){
        cin >> p >> c[i] >> w[i];
        adj[p].push_back(i);
    }
    dfs(0, 0);
    cout << ans << endl;
}