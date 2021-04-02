#include <bits/stdc++.h>
using namespace std;

int n, m, k, mat[1003][1003], color[1003], bicolorable = 1;
vector<int> adj[1003];

void dfs(int u, int c){
    color[u] = c;
    for(int v : adj[u]){
        if(color[v] == 2)
            dfs(v, 1-c);
        else if(color[v] == c)
            bicolorable = 0;
    }
}

#define num long long int

const num mod = 1e9 + 7;

int main(){
    cin >> n >> m >> k;
    int u, v;
    for(int i = 0; i < m; i++)
        cin >> u >> v, u--, v--, mat[u][v] = mat[v][u] = 1, adj[u].push_back(v), adj[v].push_back(u);
    fill_n(color, n, 2);
    for(int i = 0; i < n; i++)
        if(color[i] == 2)
            dfs(i, 0);
    num ans = 1;
    int e = (n * (n - 1)) / 2 - m;
    for(int it = e - k + 1; it <= e; it++)
        ans = (ans * it) % mod;
    if(bicolorable){
        int oc = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(!mat[i][j] && color[i] == color[j])
                    oc++;
        oc = e - oc;
        if(k <= oc){
            num dif = 1;
            for(int it = oc - k + 1; it <= oc; it++)
                dif = (dif * it) % mod;
            ans = (ans - dif + mod) % mod;
        }
    }
    cout << ans << endl;
}