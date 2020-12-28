#include <bits/stdc++.h>
using namespace std;

// March of the Penguins

const int maxn = 203;
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

#define num long long int

int N, S = 0, p[maxn], c[maxn];
num D, x[maxn], y[maxn];
double tmp;

bool solve(int meet){
    n = 2 * N + 1, m = 0, s = n - 1, t = meet;
    edges.clear();
    for(int i = 0; i < n; i++)
        adjs[i].clear();
    for(int i = 0; i < N; i++){
        add_edge(s, i, p[i]);
        add_edge(i, i + N, c[i]);
        for(int j = 0; j < N; j++)
            if(j != i){
                num dx = x[i] - x[j], dy = y[i] - y[j];
                if(10000 * (dx * dx + dy * dy) <= D * D)
                    add_edge(i + N, j, inf);
            }
    }
    return max_flow() == S;
}

vector<int> ans;

int main(){
    cin >> N >> tmp, D = static_cast<num>(tmp * 100 + 1e-9);
    for(int i = 0; i < N; i++)
        cin >> x[i] >> y[i] >> p[i] >> c[i], S += p[i];
    for(int i = 0; i < N; i++)
        if(solve(i))
            ans.push_back(i);
    if(ans.empty())
        cout << -1;
    else for(int i : ans)
        cout << i << " ";
    cout << endl;
}