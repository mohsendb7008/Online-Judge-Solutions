#include <bits/stdc++.h>
using namespace std;

// Minecraft Dungeons

const int inf = INT_MAX;

int n, m, e, dis[33][33][33][33];
char grid[33][33];
pair<int, int> us, cr, ex;
queue<pair<pair<int, int>, pair<int, int>>> bfs;

inline bool safe(int ux, int uy, int cx, int cy){
    return !(abs(ux - cx) <= e && abs(uy - cy) <= e);
}

inline pair<int, int> follow(int ux, int uy, int cx, int cy){
    bool canv = 1, canh = 1;
    if(ux < cx && grid[cx-1][cy] == 'X')
        canv = 0;
    if(ux > cx && grid[cx+1][cy] == 'X')
        canv = 0;
    if(ux == cx)
        canv = 0;
    if(uy < cy && grid[cx][cy-1] == 'X')
        canh = 0;
    if(uy > cy && grid[cx][cy+1] == 'X')
        canh = 0;
    if(uy == cy)
        canh = 0;
    if(canv && canh){
        if(abs(cx - ux) >= abs(cy - uy)){
            if(ux < cx)
                return {cx-1, cy};
            return {cx+1, cy};
        }
        if(uy < cy)
            return {cx, cy-1};
        return {cx, cy+1};
    }
    else if(canv){
        if(ux < cx)
            return {cx-1, cy};
        return {cx+1, cy};
    }
    else if(canh){
        if(uy < cy)
            return {cx, cy-1};
        return {cx, cy+1};
    }
    return {cx, cy};
}   

int adjR[5]{0, 0, -1, 1, 0};
int adjC[5]{1, -1, 0, 0, 0};

int main(){
    cin >> n >> m >> e;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'P')
                us = {i, j};
            if(grid[i][j] == 'C')
                cr = {i, j};
            if(grid[i][j] == 'E')
                ex = {i, j};
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int i2 = 0; i2 < n; i2++)
                for(int j2 = 0; j2 < m; j2++)
                    dis[i][j][i2][j2] = inf;
    dis[us.first][us.second][cr.first][cr.second] = 0;
    bfs.push({us, cr});
    while(!bfs.empty()){
        auto us = bfs.front().first;
        auto cr = bfs.front().second;
        bfs.pop();
        int d = dis[us.first][us.second][cr.first][cr.second];
        if(us == ex){
            cout << d << endl;
            return 0;
        }
        auto cr2 = follow(us.first, us.second, cr.first, cr.second);
        for(int k = 0; k < 5; k++){
            int x = us.first + adjR[k], y = us.second + adjC[k];
            if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 'X' && safe(x, y, cr2.first, cr2.second) && dis[x][y][cr2.first][cr2.second] == inf)
                dis[x][y][cr2.first][cr2.second] = d + 1, bfs.push({{x, y}, cr2});
        }
    }
    cout << "you're toast" << endl;
}