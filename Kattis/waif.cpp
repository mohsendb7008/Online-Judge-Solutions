#include <bits/stdc++.h>
using namespace std;

// Waif Until Dark

int n, m, p, tc[103], c[303][303], flow[303][303], par[303];
vector<int> adj[303];

// source: 0, monsters: [1, n], toys: [n + 1, n + m], categories: [n + m + 1, n + m + p], sink: n + m + p + 1

int augment(){
    fill_n(par, n + m + p + 2, -1);
    par[0] = -2;
    queue<pair<int, int>> bfs;
    bfs.push({0, INT_MAX});
    while(!bfs.empty()){
        int u = bfs.front().first, f = bfs.front().second;
        bfs.pop();
        if(u == n + m + p + 1)
            return f;
        for(int v : adj[u])
            if(par[v] == -1 && c[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push({v, min(f, c[u][v] - flow[u][v])});
    }
    return 0;
}

int maxflow(){
    int ans = 0;
    while(1){
        int mf = augment();
        if(!mf)
            break;
        ans += mf;
        int it = n + m + p + 1;
        while(it){
            flow[par[it]][it] += mf;
            flow[it][par[it]] -= mf;
            it = par[it];
        }
    }
    return ans;
}

int main(){
    cin >> n >> m >> p;
    int d, x;
    for(int i = 0; i < n; i++){
        cin >> d;
        while(d--)
            cin >> x, adj[i + 1].push_back(n + x), adj[n + x].push_back(i + 1), c[i + 1][n + x] = 1;
    }
    for(int i = 0; i < p; i++){
        cin >> d;
        while(d--)
            cin >> x, tc[x-1] = 1, adj[n + x].push_back(n + m + i + 1), adj[n + m + i + 1].push_back(n + x), c[n + x][n + m + i + 1] = 1;
        cin >> d;
        adj[n + m + i + 1].push_back(n + m + p + 1), adj[n + m + p + 1].push_back(n + m + i + 1), c[n + m + i + 1][n + m + p + 1] = d;
    }
    for(int i = 0; i < m; i++)
        if(!tc[i])
            adj[n + i + 1].push_back(n + m + p + 1), adj[n + m + p + 1].push_back(n + i + 1), c[n + i + 1][n + m + p + 1] = 1;
    for(int i = 0; i < n; i++)
        adj[0].push_back(i + 1), adj[i + 1].push_back(0), c[0][i + 1] = 1;
    cout << maxflow() << endl;
}