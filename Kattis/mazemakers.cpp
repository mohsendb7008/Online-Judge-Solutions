#include <bits/stdc++.h>
using namespace std;

// The Maze Makers

int n, m, e, cnt;
char g[53][53];
vector<pair<int, int>> adj[53][53];
bool vis[53][53];
pair<int, int> src, dst;

void dfs(int i, int j){
    vis[i][j] = 1, cnt++;
    for(auto a : adj[i][j])
        if(!vis[a.first][a.second])
            dfs(a.first, a.second);
}

int adjR[4]{0, 1, 0, -1};
int adjC[4]{-1, 0, 1, 0};

int main(){
    while(1){
        cin >> n >> m, e = 0, cnt = 0;
        if(!(n + m))
            break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j], adj[i][j].clear(), vis[i][j] = 0;
        src.first = -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                int mask = (g[i][j] >= 'A' && g[i][j] <= 'F') ? (g[i][j] - 'A' + 10) : (g[i][j] - '0');
                for(int k = 0; k < 4; k++)
                    if(!(mask & (1 << k))){
                        int x = i + adjR[k], y = j + adjC[k];
                        if(x >= 0 && x < n && y >= 0 && y < m)
                            adj[i][j].push_back({x, y}), e++;
                        else if(src.first == -1)
                            src = {i, j};
                        else
                            dst = {i, j};
                    }
            }
        dfs(src.first, src.second);
        if(!vis[dst.first][dst.second])
            cout << "NO SOLUTION" << endl;
        else if(cnt != n * m)
            cout << "UNREACHABLE CELL" << endl;
        else if(e / 2 >= n * m)
            cout << "MULTIPLE PATHS" << endl;
        else
            cout << "MAZE OK" << endl;
    }
}