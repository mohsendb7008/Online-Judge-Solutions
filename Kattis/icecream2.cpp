#include<bits/stdc++.h>
using namespace std;

// Ice Cream

int n, m, f, c, v, capacity[203][203], flow[203][203], par[203];
vector<int> adj[203];

bool augment(int s){
    fill_n(par, n, -1);
    par[s] = -2;
    queue<int> bfs;
    bfs.push(s);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        if(u == f)
            return true;
        for(int v : adj[u])
            if(par[v] == -1 && capacity[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push(v);
    }
    return false;
}

int main(){
    cin >> n >> m >> f >> c >> v, f--, c--, v--;
    int x, y, w;
    while(m--){
        cin >> x >> y >> w, x--, y--;
        capacity[x][y] += 2 * w;
        capacity[y][x] += 2 * w;
        adj[x].push_back(y), adj[y].push_back(x);
    }
    int ans = 0;
    while(1){
        if(!augment(c))
            break;
        int it = f;
        while(it != c){
            flow[par[it]][it]++;
            flow[it][par[it]]--;
            it = par[it];
        }
        if(!augment(v))
            break;
        it = f;
        while(it != v){
            flow[par[it]][it]++;
            flow[it][par[it]]--;
            it = par[it];
        }
        ans++;
    }
    cout << ans << endl;
}