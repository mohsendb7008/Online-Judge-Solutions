#include <bits/stdc++.h>
using namespace std;

// Flooding Fields

const int maxn = 100 * 100 * 25 * 2 + 3;
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

int N, K, H, h[103][103], cx[103], cy[103], l[27];
int adjR[5]{0, 0, 0, -1, 1};
int adjC[5]{0, 1, -1, 0, 0};

int main(){
    cin >> N >> K >> H;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> h[i][j];
    for(int i = 0; i < K; i++)
        cin >> cx[i] >> cy[i];
    for(int i = 1; i <= H; i++)
        cin >> l[i];
    n = N * N * (H + 1) * 2 + 2, m = 0, s = n - 2, t = n - 1;
    for(int i = 0; i < K; i++)
        add_edge(s, cx[i] * N * (H + 1) + cy[i] * (H + 1), 1);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            add_edge(N * N * (H + 1) + i * N * (H + 1) + j * (H + 1) + H, t, inf);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < H; k++)
                for(int c = 0; c < 5; c++){
                    int x = i + adjR[c], y = j + adjC[c];
                    if(x >= 0 && x < N && y >= 0 && y < N)
                        add_edge(N * N * (H + 1) + i * N * (H + 1) + j * (H + 1) + k, 
                                 x * N * (H + 1) + y * (H + 1) + k + 1, inf);
                }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k <= H; k++)
                if(!k || h[i][j] > l[k])
                    add_edge(i * N * (H + 1) + j * (H + 1) + k, 
                    N * N * (H + 1) + i * N * (H + 1) + j * (H + 1) + k, 1);
    cout << max_flow() << endl;
}