#include <bits/stdc++.h>
using namespace std;

// Escape Wall Maria

const int inf = INT_MAX;

int t, n, m, dis[103][103], ans = inf;
char g[103][103];
queue<pair<int, int>> bfs;
int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};
char per[4]{'L', 'R', 'D', 'U'};

int main(){
    cin >> t >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> g[i][j], dis[i][j] = inf;
            if(g[i][j] == 'S')
                dis[i][j] = 0, bfs.push({i, j});
        }
    while(!bfs.empty()){
        int ui = bfs.front().first, uj = bfs.front().second;
        bfs.pop();
        if(ui == 0 || ui == n-1 || uj == 0 || uj == m-1){
            ans = dis[ui][uj];
            break;
        }
        for(int k = 0; k < 4; k++){
            int vi = ui + adjR[k], vj = uj + adjC[k];
            if((g[vi][vj] == '0' || g[vi][vj] == per[k]) && dis[vi][vj] == inf)
                dis[vi][vj] = dis[ui][uj] + 1, bfs.push({vi, vj});
        }
    }
    if(ans == inf || ans > t)
        cout << "NOT POSSIBLE" << endl;
    else
        cout << ans << endl;   
}