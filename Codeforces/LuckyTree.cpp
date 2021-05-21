#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, vis[maxn], cc;
vector<pair<int, int>> adj[maxn];
vector<int> components;

inline bool is_lucky(int num){
    while(num){
        if((num % 10 != 4) && (num % 10 != 7))
            return false;
        num /= 10;
    }
    return true;
}

void dfs(int u){
    vis[u] = 1, cc++;
    for(auto v : adj[u])
        if(!vis[v.first] && !is_lucky(v.second))
            dfs(v.first);
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        adj[u].push_back({v, w}), adj[v].push_back({u, w});
    }
    for(int i = 0; i < n; i++)
        if(!vis[i]){
            cc = 0;
            dfs(i);
            components.push_back(cc);
        }
    long long int ans = 0;
    for(int cc : components)
        ans += (long long int)cc * (n - cc) * (n - cc - 1);
    cout << ans << endl;
}