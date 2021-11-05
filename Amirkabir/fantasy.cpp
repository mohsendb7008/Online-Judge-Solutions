#include <bits/stdc++.h>
using namespace std;

int n, m, g[20][20], taken[20][20], ans = 0;

int curr = 0;

pair<int, int> nil = {-1, -1};

// EAST - SOUTH - WEST - NORTH

int adjR[4]{0, 1, 0, -1};
int adjC[4]{1, 0, -1, 0};

inline pair<int, int> mostaghim(int i, int j, int dir){
    int x = i + adjR[dir];
    int y = j + adjC[dir];
    if(x >= 0 && x < n && y >= 0 && y < m)
        return {x, y};
    return nil;
}

void track(int i, int j, int dir){
    taken[i][j] = true;
    curr += g[i][j];
    ans = max(ans, curr);
    auto it = mostaghim(i, j, dir);
    if(it != nil && !taken[it.first][it.second]){
        track(it.first, it.second, dir);
    }
    auto it2 = mostaghim(i, j, (dir + 1) % 4);
    if(it2 != nil && !taken[it2.first][it2.second]){
        track(it2.first, it2.second, (dir + 1) % 4);
    }
    curr -= g[i][j];
    taken[i][j] = false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    track(0, 0, 0);
    cout << ans << endl;
}