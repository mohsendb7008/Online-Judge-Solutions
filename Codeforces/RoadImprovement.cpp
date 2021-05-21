#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;
const int mod = 1000000007;

#define num long long int

int n, p[maxn];
vector<int> adj[maxn];
num pi[maxn], ans[maxn], d[maxn];
vector<num> prefix[maxn], suffix[maxn];

void cpi(int u){
    pi[u] = 1;
    for(int v : adj[u]){
        cpi(v);
        pi[u] = (pi[u] * (1 + pi[v])) % mod;
        prefix[u].push_back(pi[u]);
    }
    num suf = 1;
    for(auto it = adj[u].rbegin(); it != adj[u].rend(); it++){
        int v = *it;
        suf = (suf * (1 + pi[v])) % mod;
        suffix[u].push_back(suf);
    }
    reverse(suffix[u].begin(), suffix[u].end());
}

void dfs(int u, int i){
    num mul = 1;
    if(p[u])
        mul = d[p[u]];
    if(i)
        mul = (mul * prefix[p[u]][i-1]) % mod;
    if(i+1 < adj[p[u]].size())
        mul = (mul * suffix[p[u]][i+1]) % mod;
    d[u] = (1 + mul) % mod;
    ans[u] = (pi[u] * d[u]) % mod;
    for(int j = 0; j < adj[u].size(); j++)
        dfs(adj[u][j], j);
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> p[i], p[i]--;
        adj[p[i]].push_back(i);
    }
    cpi(0);
    ans[0] = pi[0];
    for(int i = 0; i < adj[0].size(); i++)
        dfs(adj[0][i], i);
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
} 