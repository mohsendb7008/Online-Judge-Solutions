#include <bits/stdc++.h>
using namespace std;

// Avoiding the Apocalypse

const int maxn = 1003;
const int inf = INT_MAX;

struct edge{
    int u, v, cap, flow = 0;
    edge(int u, int v, int cap){
        this->u = u, this->v = v, this->cap = cap;
    }
};

int n, m = 0, s, t, ptr[maxn], level[maxn];
vector<edge> edges;
vector<int> adjs[maxn];
queue<int> q;

void add_edge(int u, int v, int cap){
    edges.push_back(edge(u, v, cap));
    edges.push_back(edge(v, u, 0));
    adjs[u].push_back(m);
    adjs[v].push_back(m + 1);
    m += 2;
}

bool bfs(){
    q.push(s);
    fill_n(level, n, -1);
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
        fill_n(ptr, n, 0);
        while(1){
            int p = dfs(s, inf);
            if(!p)
                break;
            ans += p;
        }
    }
    return ans;
}

int v, e, i, g, d, dis[maxn];
vector<int> mf;
vector<pair<int, int>> adj[maxn];
pair<pair<int, int>, pair<int, int>> connections[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> v >> i >> g >> d >> m, i--;
        mf.clear();
        for(int i = 0; i < v; i++)
            adj[i].clear();
        int x, y, p, w;
        while(m--)
            cin >> x, mf.push_back(x-1);
        cin >> e;
        for(int i = 0; i < e; i++){
            cin >> x >> y >> p >> w, x--, y--;
            connections[i] = {{x, y}, {p, w}};
            adj[x].push_back({y, w});
        }
        fill_n(dis, v, inf);
        dis[i] = 0;
        dij.push({0, i});
        while(!dij.empty()){
            int u = dij.top().second;
            int w = dij.top().first;
            dij.pop();
            if(dis[u] < w)
                continue;
            for(auto v : adj[u])
                if(w + v.second < dis[v.first])
                    dis[v.first] = w + v.second, dij.push({dis[v.first], v.first});
        }
        int l = inf, ans = 0;
        for(int x : mf)
            l = min(l, dis[x]);
        n = v + 2, s = v, t = v + 1;
        for(int ti = l; ti <= d; ti++){
            m = 0;
            edges.clear();
            for(int i = 0; i < n; i++)
                adjs[i].clear();
            add_edge(s, i, g - ans);
            for(int x : mf)
                if(dis[x] <= ti)
                    add_edge(x, t, inf);
            for(int c = 0; c < e; c++){
                int u = connections[c].first.first, v = connections[c].first.second;
                int p = connections[c].second.first, w = connections[c].second.second;
                if(dis[u] <= ti && dis[u] + w <= ti)
                    add_edge(u, v, p);
            }
            ans += max_flow();
            if(ans == g)
                break;
        }
        cout << ans << endl;
    }
}