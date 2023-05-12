#include <bits/stdc++.h>
using namespace std;

const int n = 41;
const int m = 159;

char g[n][m];
int dis[n][m];

pair<int, int> startt, endd;
queue<pair<int, int> > bfs;

int adjR[4];
int adjC[4];

int main(){
    adjR[0] = adjR[1] = 0;
    adjR[2] = 1, adjR[3] = -1;
    adjC[0] = 1, adjC[1] = -1;
    adjC[2] = adjC[3] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            dis[i][j] = INT_MAX;
            if(g[i][j] == 'S'){
                startt = make_pair(i, j);
                g[i][j] = 'a';
            }
            else if(g[i][j] == 'E'){
                endd = make_pair(i, j);
                g[i][j] = 'z';
            }
        }
    dis[startt.first][startt.second] = 0;
    bfs.push(startt);
    while(!bfs.empty()){
        auto u = bfs.front();
        bfs.pop();
        for(int k = 0; k < 4; k++){
            int x = u.first + adjR[k];
            int y = u.second + adjC[k];
            if(x >= 0 && x < n && y >= 0 && y < m && dis[x][y] == INT_MAX && g[x][y] - g[u.first][u.second] <= 1){
                dis[x][y] = dis[u.first][u.second] + 1;
                bfs.push(make_pair(x, y));
            }
        }
    }
    cout << dis[endd.first][endd.second] << endl;
}