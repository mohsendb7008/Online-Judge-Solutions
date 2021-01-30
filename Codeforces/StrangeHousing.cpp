#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 3;

int n, m, color[maxn], visited;
vector<int> adj[maxn];
set<int> ans;

void dfs(int u, int c){
    visited++;
    if(c){
        for(int v : adj[u])
            if(color[v] == 1){
                c = 0;
                break;
            }
    }
    color[u] = c;
    if(c)
        ans.insert(u);
    for(int v : adj[u])
        if(color[v] == 2)
            dfs(v, 1 - c);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        int u, v;
        while(m--)
            cin >> u >> v, adj[u - 1].push_back(v - 1), adj[v - 1].push_back(u - 1);
        fill_n(color, n, 2);
        ans.clear();
        visited = 0;
        dfs(0, 1);
        if(visited < n)
            cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << ans.size() << endl;
            for(int u : ans)
                cout << u + 1 << " ";
            cout << endl;
        }
    }
}
