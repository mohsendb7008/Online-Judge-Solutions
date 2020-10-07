#include <bits/stdc++.h>
using namespace std;

// Wet Tiles

const int inf = INT_MAX;

int n, m, t, l, w, dist[1003][1003];
char g[1003][1003];
queue<pair<int, int>> bfs;
int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

int main(){
    while(cin >> n){
        if(n == -1)
            break;
        cin >> m >> t >> l >> w;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                g[i][j] = '.', dist[i][j] = inf;
        int x, y;
        while(l--)
            cin >> x >> y, x--, y--, dist[x][y] = 1, bfs.push({x, y});
        int x1, y1, x2, y2;
        while(w--){
            cin >> x1 >> y1 >> x2 >> y2, x1--, y1--, x2--, y2--;
            if(x1 == x2 && y1 == y2)
                g[x1][y1] = '#';
            else if(x1 == x2)
                for(int y = min(y1, y2); y <= max(y1, y2); y++)
                    g[x1][y] = '#';
            else if(y1 == y2)
                for(int x = min(x1, x2); x <= max(x1, x2); x++)
                    g[x][y1] = '#';
            else{
                int ix = x2 > x1 ? 1 : -1, iy = y2 > y1 ? 1 : -1;
                while(!(x1 == x2 && y1 == y2))
                    g[x1][y1] = '#', x1 += ix, y1 += iy;
                g[x1][y1] = '#';    
            }
        }
        while(!bfs.empty()){
            int i = bfs.front().first, j = bfs.front().second;
            bfs.pop();
            for(int k = 0; k < 4; k++){
                int x = i + adjR[k], y = j + adjC[k];
                if(x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == inf && g[x][y] == '.')
                    dist[x][y] = dist[i][j] + 1, bfs.push({x, y});
            }           
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(dist[i][j] <= t)
                    ans++;
        cout << ans << endl;
    }
}