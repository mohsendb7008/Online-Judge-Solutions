#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, dis[maxn];
vector<int> adj[maxn];
queue<int> bfs;

int main(){
    cin >> n;
    int u, v;
    for(int i = 0; i < n - 1; i++)
        cin >> u >> v, adj[u - 1].push_back(v - 1), adj[v - 1].push_back(u - 1);
    cin >> u >> v, u--, v--;
    fill_n(dis, n, -1);
    dis[u] = 0;
    bfs.push(u);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : adj[u])
            if(dis[v] == -1)
                dis[v] = dis[u] + 1, bfs.push(v);
    }
    cout << (dis[v] % 2 ? "karakter e komaki_2" : "karakter e komaki_1") << endl;
}