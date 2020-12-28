#include <bits/stdc++.h>
using namespace std;

// The King of the North

const int maxn = 2 * 90003;
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

int N, M, g[303][303], cx, cy;

int adjR[4]{0, 0, -1, 1};
int adjC[4]{-1, 1, 0, 0};

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> g[i][j];
    cin >> cx >> cy;
    n = 2 * N * M + 2, s = n - 2, t = n - 1;
    add_edge(s, cx * M + cy, inf);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(!i || !j || i == N-1 || j == M-1)
                add_edge(N * M + i * M + j, t, inf);
            add_edge(i * M + j, N * M + i * M + j, g[i][j]);
            for(int k = 0; k < 4; k++){
                int x = i + adjR[k], y = j + adjC[k];
                if(x >= 0 && x < N && y >= 0 && y < M)
                    add_edge(N * M + i * M + j, x * M + y, inf);
            }
        }
    cout << max_flow() << endl;
}