#include <bits/stdc++.h>
using namespace std;

// Fire!

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

int n, m;
char g[1003][1003];
int dis[1003][1003];
queue<pair<char, pair<int, int>>> bfs;
vector<pair<int, int>> adj[1003][1003];

int main(){
    cin >> n >> m;
    g[n][m] = '.';
    dis[n][m] = INT_MAX;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            dis[i][j] = INT_MAX;
            if(g[i][j] == 'J')
                g[i][j] = '.', dis[i][j] = 0, bfs.push({'J', {i, j}}); 
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j] == 'F')
                bfs.push({'F', {i, j}});
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j] != '#'){
                for(int k = 0; k < 4; k++){
                    int x = i + adjR[k], y = j + adjC[k];
                    if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#')
                        adj[i][j].push_back({x, y});
                }
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                    adj[i][j].push_back({n, m});
            }
    while(!bfs.empty()){
        char type = bfs.front().first;
        int u = bfs.front().second.first, v = bfs.front().second.second;
        bfs.pop();
        if(type == 'F'){
            for(int k = 0; k < 4; k++){
                int x = u + adjR[k], y = v + adjC[k];
                if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.')
                    g[x][y] = 'F', bfs.push({'F', {x, y}});
            }
        }
        else if(g[u][v] == '.'){
            for(pair<int, int> pq : adj[u][v])
                if(g[pq.first][pq.second] == '.' && dis[pq.first][pq.second] == INT_MAX)
                    dis[pq.first][pq.second] = dis[u][v] + 1, bfs.push({'J', pq});
        }
    }
    if(dis[n][m] == INT_MAX)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << dis[n][m] << endl;
}