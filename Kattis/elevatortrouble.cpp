#include <bits/stdc++.h>
using namespace std;

// Elevator Trouble

const int maxf = 1e6 + 3;
const int inf = INT_MAX;

int f, s, g, u, d, dist[maxf];
vector<int> adj[maxf];
queue<int> bfs;

int main(){
    cin >> f >> s >> g >> u >> d, s--, g--;
    for(int i = 0; i < f; i++){
        if(i + u < f)
            adj[i].push_back(i + u);
        if(i - d >= 0)
            adj[i].push_back(i - d);
    }
    fill_n(dist, f, inf);
    dist[s] = 0, bfs.push(s);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : adj[u])
            if(dist[v] == inf)
                dist[v] = dist[u] + 1, bfs.push(v);
    }
    if(dist[g] == inf)
        cout << "use the stairs" << endl;
    else 
        cout << dist[g] << endl;
}