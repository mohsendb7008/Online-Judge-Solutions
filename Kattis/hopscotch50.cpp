#include <bits/stdc++.h>
using namespace std;

// Hopscotch 50

#define inf INT_MAX

int n, k;
int g[53][53], dis[53][53];
vector<pair<int, int>> v[2503];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> dij;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
            dis[i][j] = inf; 
            v[g[i][j]].push_back({i, j});
        }
    for(pair<int, int> src : v[1])
        dis[src.first][src.second] = 0, dij.push({0, src});
    while(!dij.empty()){
        int w = dij.top().first;
        pair<int, int> u = dij.top().second;
        dij.pop();
        if(dis[u.first][u.second] < w)
            continue;
        for(pair<int, int> p : v[g[u.first][u.second] + 1]){
            int nw = w + abs(p.first - u.first) + abs(p.second - u.second);
            if(nw < dis[p.first][p.second])
                dis[p.first][p.second] = nw, dij.push({nw, p});
        }
    }
    int ans = inf;
    for(pair<int, int> dst : v[k])
        ans = min(ans, dis[dst.first][dst.second]);
    if(ans == inf)
        ans = -1;
    cout << ans << endl;
}