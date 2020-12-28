#include <bits/stdc++.h>
using namespace std;

// Surely You Congest

#define inf INT_MAX

const int maxn = 35e3 + 3;
struct edge{
    int u, v, cap, flow = 0;
    edge(int u, int v, int cap){
        this->u = u, this->v = v, this->cap = cap;
    }
};

int n, m, c;
vector<pair<int, int>> dadjs[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dis[maxn];
int car[maxn];
bool vis[maxn];

vector<edge> edges;
vector<int> adjs[maxn];
int ptr[maxn];
queue<int> q;
int level[maxn];
int s, t;
map<int, vector<int>> same;
int nodes;

void add_edge(int u, int v, int cap){
    edges.push_back(edge(u, v, cap));
    edges.push_back(edge(v, u, 0));
    adjs[u].push_back(m);
    adjs[v].push_back(m + 1);
    m += 2;
}

void build(int u){
    vis[u] = 1;
    for(auto x : dadjs[u]){
        if(dis[x.first] + x.second == dis[u]){
            add_edge(u, x.first, 1);
            if(!vis[x.first])
                build(x.first);
        }
    }
}

bool bfs(){
    q.push(s);
    fill_n(level, nodes + 1, -1);
    level[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int eid : adjs[u]){
            int v = edges[eid].v;
            if(edges[eid].cap - edges[eid].flow == 0)
                continue;
            if(level[v] == -1)
                q.push(v), level[v] = level[u] + 1;
        }
    }
    return level[t] != -1;
}

int dfs(int u, int pushed){
    if(u == t)
        return pushed;
    for(; ptr[u] < adjs[u].size(); ptr[u]++){
        int cid = ptr[u];
        auto& e = edges[adjs[u][cid]];
        int v = e.v;
        if(e.cap - e.flow == 0 || level[v] != level[u] + 1)
            continue;
        int tr = dfs(v, min(pushed, e.cap - e.flow));
        if(tr == 0)
            continue;
        e.flow += tr;
        edges[adjs[u][cid] ^ 1].flow -= tr;
        return tr;
    }
    return 0;
}

int max_flow(){
    int ans = 0;
    while(bfs()){
        fill_n(ptr, nodes + 1, 0);
        while(1){
            int p = dfs(s, inf);
            if(!p)
                break;
            ans += p;
        }
    }
    return ans;
}

int main(){
    cin >> n >> m >> c;
    for(int i = 0; i < m; i++){
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        dadjs[u].push_back({v, t}), dadjs[v].push_back({u, t});
    }
    m = 0;
    for(int i = 0; i < c; i++){
        int x;
        cin >> x;
        x--;
        car[x]++;
    }
    pq.push({0, 0});
    fill_n(dis, n, inf);
    dis[0] = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int u = p.second, d = p.first;
        if(dis[u] < d)
            continue;
        for(auto x : dadjs[u])
            if(dis[x.first] > d + x.second)
                dis[x.first] = d + x.second, pq.push({dis[x.first], x.first});
    }
    s = n, t = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(car[i])
            same[dis[i]].push_back(i);
    for(auto p : same){
        nodes = n;
        m = 0;
        edges.clear();
        for(int i = 0; i <= n + c; i++)
            adjs[i].clear();
        fill_n(vis, n + c + 1, 0);
        for(int u : p.second)
            if(!vis[u])
                build(u);
        for(int u : p.second)
            for(int k = 0; k < car[u]; k++)
                add_edge(n, ++nodes, 1), add_edge(nodes, u, 1);
        ans += max_flow();
    }
    cout << ans << endl;
}