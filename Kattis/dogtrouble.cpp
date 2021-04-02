#include <bits/stdc++.h>
using namespace std;

// Dog Trouble

const int maxn = 103;
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

int n, m, dogs[53][53];
set<int> cand;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> dogs[i][j], cand.insert(dogs[i][j]);
    N = n + m + 2, src = 0, sink = N - 1;
    int ans = INT_MAX;
    for(int t : cand){
        for(int i = 0; i < N; i++){
            picked[i] = 0;
            for(int j = 0; j < N; j++)
                cap[i][j] = flow[i][j] = cost[i][j] = 0;
        }
        for(int i = 0; i < n; i++)
            cap[src][i+1] = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(dogs[i][j] <= t)
                    cap[i+1][j+n+1] = 1, cost[i+1][j+n+1] = t - dogs[i][j];
        for(int j = 0; j < m; j++)
            cap[j+n+1][sink] = 1;
        auto mcmf = mincost_maxflow();
        if(mcmf.first == n)
            ans = min(ans, mcmf.second);
    }
    cout << ans << endl;
}