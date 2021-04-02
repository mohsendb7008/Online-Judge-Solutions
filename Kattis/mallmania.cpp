#include <bits/stdc++.h>
using namespace std;

// Mall Mania

#define inf INT_MAX

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

int n, dis[2003][2003];
queue<pair<int, int>> bfs;

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i <= 2000; i++)
            for(int j = 0; j <= 2000; j++)
                dis[i][j] = inf;
        int x, y;
        while(n--)
            cin >> x >> y, dis[x][y] = 0, bfs.push({x, y});
        while(!bfs.empty()){
            int ux = bfs.front().first, uy = bfs.front().second;
            bfs.pop();
            for(int k = 0; k < 4; k++){
                int vx = ux + adjR[k], vy = uy + adjC[k];
                if(vx >= 0 && vx < 2001 && vy >= 0 && vy < 2001 && dis[vx][vy] == inf)
                    dis[vx][vy] = dis[ux][uy] + 1, bfs.push({vx, vy});
            }
        }
        int ans = inf;
        cin >> n;
        while(n--)
            cin >> x >> y, ans = min(ans, dis[x][y]);
        cout << ans << endl;
    }
}