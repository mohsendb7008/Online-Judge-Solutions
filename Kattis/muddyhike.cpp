#include <bits/stdc++.h>
using namespace std;

// Muddy Hike

int r, c, g[1003][1003];
bool vis[1003][1003];

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

void dfs(int i, int j, int d){
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < r && y >= 0 && y < c && !vis[x][y] && g[x][y] <= d)
            dfs(x, y, d);
    }
}

bool judge(int d){
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            vis[i][j] = false;
    for(int i = 0; i < r; i++)
        if(!vis[i][0] && g[i][0] <= d)
            dfs(i, 0, d);
    for(int i = 0; i < r; i++)
        if(vis[i][c-1])
            return true;
    return false;
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> g[i][j];
    int lo = 0, hi = 1e6;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}