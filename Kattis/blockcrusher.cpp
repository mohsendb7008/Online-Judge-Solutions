#include <bits/stdc++.h>
using namespace std;

// Block Crusher

#define inf INT_MAX

int adjR[8]{0, 0, 1, -1, 1, -1, 1, -1};
int adjC[8]{1, -1, 0, 0, 1, -1, -1, 1};

int n, m;
char g[23][63];
int dis[23][63], par[23][63];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> dij;

int main(){
    while(1){
        cin >> n >> m;
        if(!(n + m))
            break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j], dis[i][j] = inf, par[i][j] = -1;
        dis[n][m] = inf, par[n][m] = -1;
        for(int j = 0; j < m; j++)
            dis[0][j] = 0, dij.push({0, {0, j}});
        while(!dij.empty()){
            int w = dij.top().first, u = dij.top().second.first, v = dij.top().second.second, c = g[u][v] - '0';
            dij.pop();
            if(dis[u][v] < w)
                continue;
            for(int k = 0; k < 8; k++){
                int x = u + adjR[k], y = v + adjC[k];
                if(x >= 0 && x < n && y >= 0 && y < m && w + c < dis[x][y])
                    dis[x][y] = w + c, par[x][y] = k, dij.push({w + c, {x, y}});
            }
            if(u == n - 1 && w + c < dis[n][m])
                dis[n][m] = w + c, par[n][m] = v;
        }
        int uit = n - 1, vit = par[n][m];
        while(1){
            g[uit][vit] = ' ';
            int k = par[uit][vit];
            if(k == -1)
                break;
            uit -= adjR[k], vit -= adjC[k];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << g[i][j];
            cout << endl;
        }
        cout << endl;
    }

}