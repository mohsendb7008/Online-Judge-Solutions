#include <bits/stdc++.h>
using namespace std;

// Raging River

const int maxn = 1503;
const int inf = INT_MAX;

int N, M, src, sink;
bool found[maxn];
int cap[maxn][maxn], flow[maxn][maxn], par[maxn], dis[maxn], picked[maxn], cost[maxn][maxn];

bool aug(){
    fill_n(found, N, false);
    fill_n(dis, N + 1, inf);
    int it = src;
    dis[it] = 0;
    while(it != N){
        int best = N;
        found[it] = true;
        for(int k = 0; k < N; k++){
            if(found[k])
                continue;
            if(flow[k][it] != 0){
                int val = dis[it] + picked[it] - picked[k] - cost[k][it];
                if(dis[k] > val)
                    dis[k] = val, par[k] = it;
            }
            if(flow[it][k] < cap[it][k]){
                int val = dis[it] + picked[it] - picked[k] + cost[it][k];
                if(dis[k] > val)
                    dis[k] = val, par[k] = it;
            }
            if(dis[k] < dis[best])
                best = k;
        }
        it = best;
    }
    for(int k = 0; k < N; k++)
        if(dis[k] != inf)
            picked[k] += dis[k];
    return found[sink];
}

pair<int, int> mincost_maxflow(){
    int tf = 0;
    int tc = 0;
    while(aug()){
        int f = inf;
        for(int x = sink; x != src; x = par[x]){
            if(flow[x][par[x]] != 0)
                f = min(f, flow[x][par[x]]);
            else
                f = min(f, cap[par[x]][x] - flow[par[x]][x]);
        }
        tf += f;
        for(int x = sink; x != src; x = par[x]){
            if(flow[x][par[x]] != 0){
                flow[x][par[x]] -= f;
                tc -= cost[x][par[x]] * f;
            }
            else{
                flow[par[x]][x] += f;
                tc += cost[par[x]][x] * f;
            }   
        }
    }
    return {tf, tc};
}

int P, R, L;

int main(){
    cin >> P >> R >> L;
    N = R + 2, src = R, sink = R + 1;
    int u, v;
    while(L--){
        cin >> u >> v;
        if(u == -2)
            u = src;
        if(u == -1)
            u = sink;
        if(v == -2)
            v = src;
        if(v == -1)
            v = sink;
        cap[u][v] = cap[v][u] = cost[u][v] = cost[v][u] = 1;
    }
    cap[sink][sink+1] = cap[sink+1][sink] = P;
    N++, sink++;
    auto ans = mincost_maxflow();
    if(ans.first < P)
        cout << P - ans.first << " people left behind" << endl;
    else
        cout << ans.second << endl;
}