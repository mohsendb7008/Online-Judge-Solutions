#include <bits/stdc++.h>
using namespace std;

// Tours de Sales Force

inline double dist(pair<int, int>& f, pair<int, int>& s){
    double dx = f.first - s.first, dy = f.second - s.second;
    return sqrt(dx * dx + dy * dy);
}

vector<pair<int, int>> curr;
double tsp[(1 << 16) + 3][16 + 3];

inline double csp(){
    int siz = curr.size() - 1;
    for(int mask = 1; mask < (1 << siz); mask++)
        for(int i = 0; i < siz; i++){
            if(mask == (1 << i))
                tsp[mask][i] = dist(curr[0], curr[i+1]);
            else if(mask & (1 << i)){
                tsp[mask][i] = LLONG_MAX;
                for(int j = 0; j < siz; j++)
                    if(j != i && (mask & (1 << j)))
                        tsp[mask][i] = min(tsp[mask][i], tsp[mask - (1 << i)][j] + dist(curr[j+1], curr[i+1]));
            }
        }
    double ans = LLONG_MAX;
    for(int i = 0; i < siz; i++)
        ans = min(ans, tsp[(1 << siz) - 1][i] + dist(curr[i+1], curr[0]));
    return ans;
}

int d;
vector<pair<int, int>> region[53];

#define num double

const int maxn = 53;
const num inf = LLONG_MAX;

int N, src, sink;
bool found[maxn];
int cap[maxn][maxn], flow[maxn][maxn], par[maxn];
num picked[maxn], dis[maxn], cost[maxn][maxn];

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
                num val = dis[it] + picked[it] - picked[k] - cost[k][it];
                if(dis[k] > val)
                    dis[k] = val, par[k] = it;
            }
            if(flow[it][k] < cap[it][k]){
                num val = dis[it] + picked[it] - picked[k] + cost[it][k];
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

pair<int, num> mincost_maxflow(){
    int tf = 0;
    num tc = 0;
    while(aug()){
        int f = INT_MAX;
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

int main(){
    cin >> d;
    double ans = 0;
    for(int i = 0; i < d; i++){
        int s, x, y;
        cin >> s;
        while(s--)
            cin >> x >> y, region[i].push_back({x, y});
        curr = region[i];
        ans += csp();
    }
    N = d + 2, src = 0, sink = d + 1;
    for(int i = 0; i < d / 2; i++)
        cap[src][i+1] = 1;
    for(int i = 0; i < d / 2; i++)
        for(int j = d / 2; j < d; j++){
            curr.clear();
            for(pair<int, int> p : region[i])
                curr.push_back(p);
            for(pair<int, int> p : region[j])
                curr.push_back(p);
            cap[i+1][j+1] = 1;
            cost[i+1][j+1] = csp();
        }
    for(int j = d / 2; j < d; j++)
        cap[j+1][sink] = 1;
    cout << fixed << setprecision(6) << ans << " " << mincost_maxflow().second << endl;
}