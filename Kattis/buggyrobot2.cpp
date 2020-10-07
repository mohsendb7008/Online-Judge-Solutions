#include <bits/stdc++.h>
using namespace std;

// Buggy Robot

#define inf INT_MAX

int r, c, n, dis[53][53][53];
char g[53][53];
pair<int, int> src, dst;
string s;

struct state{
    int x, y, i;

    state(int x, int y, int i){
        this->x = x;
        this->y = y;
        this->i = i;
    }

    bool operator<(const state& o) const{
        return this->x < o.x;
    }
};

priority_queue<pair<int, state>, vector<pair<int, state>>, greater<pair<int, state>>> dij;

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};
map<char, int> dir{{'L', 1}, {'R', 0}, {'U', 2}, {'D', 3}};

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            cin >> g[i][j];
            if(g[i][j] == 'R')
                g[i][j] = '.', src = {i, j};
            if(g[i][j] == 'E')
                g[i][j] = '.', dst = {i, j};
        }
    cin >> s, n = s.size();
    for(int x = 0; x < r; x++)
        for(int y = 0; y < c; y++)
            for(int i = 0; i <= n; i++)
                dis[x][y][i] = inf;
    dis[src.first][src.second][0] = 0;
    dij.push({0, state(src.first, src.second, 0)});
    while(!dij.empty()){
        state u = dij.top().second;
        int w = dij.top().first;
        dij.pop();
        if(dis[u.x][u.y][u.i] < w)
            continue;
        if(u.x == dst.first && u.y == dst.second){
            cout << w << endl;
            return 0;
        }
        if(u.i < n){
            int x = u.x, y = u.y, k = dir[s[u.i]];
            int nx = x + adjR[k], ny = y + adjC[k];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] == '.')
                x = nx, y = ny;
            if(w < dis[x][y][u.i+1]) // send command
                dis[x][y][u.i+1] = w, dij.push({w, state(x, y, u.i+1)});
            if(w + 1 < dis[u.x][u.y][u.i+1]) // delete command
                dis[u.x][u.y][u.i+1] = w + 1, dij.push({w + 1, state(u.x, u.y, u.i+1)});
        }
        // insert commands
        for(int k = 0; k < 4; k++){
            int x = u.x, y = u.y;
            int nx = x + adjR[k], ny = y + adjC[k];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] == '.')
                x = nx, y = ny;
            if(w + 1 < dis[x][y][u.i])
                dis[x][y][u.i] = w + 1, dij.push({w + 1, state(x, y, u.i)});
        }
    }
}