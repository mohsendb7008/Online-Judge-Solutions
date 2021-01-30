#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num inf = LLONG_MAX;

int n, m;
num grid[2003][2003], dis[2003][2003];
priority_queue<pair<num, pair<int, int>>, vector<pair<num, pair<int, int>>>, greater<pair<num, pair<int, int>>>> dij;

int adjR[3]{0, 0, 1};
int adjC[3]{1, -1, 0};

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j], dis[i][j] = inf;
    dis[0][0] = grid[0][0];
    dij.push({grid[0][0], {0, 0}});
    while(!dij.empty()){
        num w = dij.top().first;
        int ux = dij.top().second.first, uy = dij.top().second.second;
        dij.pop();
        if(dis[ux][uy] < w)
            continue;
        for(int k = 0; k < 3; k++){
            int vx = ux + adjR[k], vy = uy + adjC[k];
            if(vx >= 0 && vx < n && vy >= 0 && vy < m && w + grid[vx][vy] < dis[vx][vy])
                dis[vx][vy] = w + grid[vx][vy], dij.push({dis[vx][vy], {vx, vy}});
        }
    }
    cout << dis[n-1][m-1] << endl;
}