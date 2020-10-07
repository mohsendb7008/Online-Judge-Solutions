#include <bits/stdc++.h>
using namespace std;

// Absurdistan Roads III

const int maxn = 100003;

int n, deg[maxn];
vector<int> adj[maxn];
queue<int> kahn;

vector<int> cycle;

void dfs(int u){
    deg[u] = 0;
    cycle.push_back(u);
    for(int v : adj[u])
        if(deg[v])
            dfs(v);
}

int main(){
    int u, v;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> u >> v, u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    for(int i = 0; i < n; i++)
        if(deg[i] == 1)
            kahn.push(i);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        deg[u] = 0;
        for(int v : adj[u])
            if(deg[v]){
                cout << u + 1 << " " << v + 1 << endl;
                deg[v]--;
                if(deg[v] == 1)
                    kahn.push(v);
            }
    }
    for(int i = 0; i < n; i++)
        if(deg[i]){
            cycle.clear();
            dfs(i);
            for(int i = 0; i < cycle.size() - 1; i++)
                cout << cycle[i] + 1 << " " << cycle[i + 1] + 1 << endl;
            cout << cycle.back() + 1 << " " << cycle[0] + 1 << endl;
        }
}