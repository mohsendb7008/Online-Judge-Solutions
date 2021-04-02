#include <bits/stdc++.h>
using namespace std;

int n, dis[1003], q, p[1003];
vector<int> adj[1003];
queue<int> bfs;

bool cmp(int i, int j){
    if(dis[i] == dis[j])
        return i < j;
    return dis[i] < dis[j];
}

int main(){
    int u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++)
        cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);
    fill_n(dis, n, -1);
    dis[0] = 0;
    bfs.push(0);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : adj[u])
            if(dis[v] == -1)
                dis[v] = dis[u] + 1, bfs.push(v);
    }
    cin >> q;
    for(int i = 0; i < q; i++)
        cin >> p[i], p[i]--;
    cout << *min_element(p, p + q, cmp) + 1 << endl;
}