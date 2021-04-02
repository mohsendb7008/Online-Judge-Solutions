#include <bits/stdc++.h>
using namespace std;

// Gravamen

const int maxn = 6003;
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

int R, S, L, A[2003], B[2003];

bool judge(int ans){
    m = 0, edges.clear();
    for(int i = 0; i < n; i++)
        adjs[i].clear();
    for(int i = 0; i < L; i++)
        add_edge(s, i, 1), add_edge(i, L + A[i], 1), add_edge(i, L + R + B[i], 1);
    for(int i = 0; i < R; i++)
        add_edge(L + i, t, ans);
    for(int i = 0; i < S; i++)
        add_edge(L + R + i, t, ans);
    return max_flow() == L;
}

int main(){
    cin >> R >> S >> L;
    for(int i = 0; i < L; i++)
        cin >> A[i] >> B[i], A[i]--, B[i]--;
    n = L + R + S + 2, s = L + R + S, t = L + R + S + 1;
    int lo = 1, hi = L;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    judge(lo);
    for(auto e : edges)
        if(e.u < L && e.flow == 1){
            if(e.v < L + R)
                cout << "INDV " << e.v - L + 1 << endl;
            else
                cout << "CORP " << e.v - (L + R) + 1 << endl;
        }
}