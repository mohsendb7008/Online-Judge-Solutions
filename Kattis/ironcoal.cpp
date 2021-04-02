#include <bits/stdc++.h>
using namespace std;

// Iron and Coal

const int maxn = 1e5 + 3;
const int inf = INT_MAX;

int n, i, c, dis[maxn], disi[maxn], disc[maxn];
vector<int> iron, coal, adj[maxn], radj[maxn];
queue<int> bfs;

int main(){
    cin >> n >> i >> c;
    int x, y;
    for(int j = 0; j < i; j++)
        cin >> x, iron.push_back(x-1);
    for(int j = 0; j < c; j++)
        cin >> x, coal.push_back(x-1);
    for(int i = 0; i < n; i++){
        cin >> x;
        while(x--)
            cin >> y, adj[i].push_back(y-1), radj[y-1].push_back(i);
    }
    fill_n(dis, n, inf);
    dis[0] = 0;
    bfs.push(0);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : adj[u])
            if(dis[v] == inf)
                dis[v] = dis[u] + 1, bfs.push(v);
    }
    fill_n(disi, n, inf);
    for(int i : iron)
        disi[i] = 1, bfs.push(i);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : radj[u])
            if(disi[v] == inf)
                disi[v] = disi[u] + 1, bfs.push(v);
    }
    fill_n(disc, n, inf);
    for(int c : coal)
        disc[c] = 1, bfs.push(c);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : radj[u])
            if(disc[v] == inf)
                disc[v] = disc[u] + 1, bfs.push(v);
    }
    int ans = inf;
    for(int i = 0; i < n; i++)
        if(dis[i] != inf && disi[i] != inf && disc[i] != inf)
            ans = min(ans, dis[i] + disi[i] + disc[i] - 2);
    if(ans == inf)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
}