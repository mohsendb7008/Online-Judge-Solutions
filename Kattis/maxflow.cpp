#include <bits/stdc++.h>
using namespace std;

// Maximum Flow

int n, m, s, t, par[503], c[503][503], flow[503][503];
vector<int> adj[503];

bool augment(){
    fill_n(par, n, -1);
    par[s] = -2;
    queue<int> bfs;
    bfs.push(s);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        if(u == t)
            return true;
        for(int v : adj[u])
            if(par[v] == -1 && c[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push(v);
    }
    return false;
}

vector<int> path;

int max_flow(){
    int ans = 0;
    while(augment()){
        path.clear();
        int it = t, mf = INT_MAX;
        while(1){
            path.push_back(it);
            if(it == s)
                break;
            mf = min(mf, c[par[it]][it] - flow[par[it]][it]);
            it = par[it];
        }
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size() - 1; i++)
            flow[path[i]][path[i+1]] += mf, flow[path[i+1]][path[i]] -= mf;
        ans += mf;
    }
    return ans;
}

vector<pair<int, int>> edges;

int main(){
    cin >> n >> m >> s >> t;
    int u, v, d;
    while(m--)
        cin >> u >> v >> d, c[u][v] = d, adj[u].push_back(v), adj[v].push_back(u);
    cout << n << " " << max_flow() << " ";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(flow[i][j] > 0)
                edges.push_back({i, j});
    cout << edges.size() << endl;
    for(pair<int, int> p : edges)
        cout << p.first << " " << p.second << " " << flow[p.first][p.second] << endl;
}