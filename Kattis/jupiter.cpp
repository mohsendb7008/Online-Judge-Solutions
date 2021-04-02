#include <bits/stdc++.h>
using namespace std;

// Jupiter Orbiter

#define num long long int

const int maxn = 2003;
const num inf = LLONG_MAX;

int n, q, s, fed[maxn], v, src, sink, par[maxn];
num sum = 0, c[maxn][maxn], flow[maxn][maxn];
vector<int> adj[maxn];

num augment(){
    fill_n(par, v, -1);
    par[src] = -2;
    queue<pair<int, num>> bfs;
    bfs.push({src, inf});
    while(!bfs.empty()){
        int u = bfs.front().first;
        num f = bfs.front().second;
        bfs.pop();
        if(u == sink)
            return f;
        for(int v : adj[u])
            if(par[v] == -1 && c[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push({v, min(f, c[u][v] - flow[u][v])});
    }
    return 0;
}

num maxflow(){
    num ans = 0;
    while(1){
        num mf = augment();
        if(!mf)
            break;
        ans += mf;
        int it = sink;
        while(it != src){
            flow[par[it]][it] += mf;
            flow[it][par[it]] -= mf;
            it = par[it];
        }
    }
    cerr << ans << endl;
    return ans;
}

// src: 0, sink: s + 2 * n * q + n + 1
// sensors: [1 -> s]
// queues1: [s + 1 -> s + n * q]
// queues2: [s + n * q + 1 -> s + 2 * n * q]
// downlinks: [s + 2 * n * q + 1 -> s + 2 * n * q + n]

int main(){
    cin >> n >> q >> s, v = s + 2 * n * q + n + 2, src = 0, sink = v - 1;
    for(int i = 0; i < s; i++){
        cin >> fed[i], fed[i]--;
        adj[src].push_back(i + 1), adj[i + 1].push_back(src), c[src][i + 1] = inf;
    }
    for(int i = 0; i < q; i++){
        num w;
        cin >> w;
        for(int j = 0; j < n; j++){
            int u = s + j * q + i + 1, v = u + n * q;
            adj[u].push_back(v), adj[v].push_back(u), c[u][v] = w;
            int d = s + 2 * n * q + j + 1;
            adj[v].push_back(d), adj[d].push_back(v), c[v][d] = inf;
            if(j < n - 1){
                int k = u + q;
                adj[v].push_back(k), adj[k].push_back(v), c[v][k] = inf;
            }
        }
    }
    for(int i = 0; i < n; i++){
        num w;
        cin >> w;
        adj[s + 2 * n * q + i + 1].push_back(sink), adj[sink].push_back(s + 2 * n * q + i + 1), c[s + 2 * n * q + i + 1][sink] = w;
        for(int j = 0; j < s; j++){
            cin >> w, sum += w;
            int u = j + 1, v = s + i * q + fed[j] + 1;
            adj[u].push_back(v), adj[v].push_back(u), c[u][v] = w;
        }
    }
    cout << (maxflow() == sum ? "possible" : "impossible") << endl;
}