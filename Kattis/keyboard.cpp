#include <bits/stdc++.h>
using namespace std;

// Keyboarding

struct state{
    int x, y, ind;

    state(int x, int y, int ind){
        this->x = x;
        this->y = y;
        this->ind = ind;
    }
};

int n, m, s, dis[53][53][10003], skip[4][53][53];
char g[53][53];
string type;
queue<state> bfs;

int adjR[4]{0, 0, 1, -1};
int adjC[4]{1, -1, 0, 0};

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    cin >> type;
    type.push_back('*');
    s = type.size();
    for(int j = m-1; j >= 0; j--)
        for(int i = 0; i < n; i++){
            skip[0][i][j] = 1;
            if(j + 1 < m && g[i][j] == g[i][j + 1])
                skip[0][i][j] += skip[0][i][j + 1];
        }
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++){
            skip[1][i][j] = 1;
            if(j && g[i][j] == g[i][j - 1])
                skip[1][i][j] += skip[1][i][j - 1];
        }
    for(int i = n-1; i >= 0; i--)
        for(int j = 0; j < m; j++){
            skip[2][i][j] = 1;
            if(i + 1 < n && g[i][j] == g[i + 1][j])
                skip[2][i][j] += skip[2][i + 1][j];
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            skip[3][i][j] = 1;
            if(i && g[i][j] == g[i - 1][j])
                skip[3][i][j] += skip[3][i - 1][j];
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k <= s; k++)
                dis[i][j][k] = -1;
    dis[0][0][0] = 0;
    bfs.push(state(0, 0, 0));
    while(!bfs.empty()){
        auto st = bfs.front();
        bfs.pop();
        int ux = st.x, uy = st.y, k = st.ind;
        if(k == s){
            cout << dis[ux][uy][k] << endl;
            return 0;
        }
        if(g[ux][uy] == type[k] && dis[ux][uy][k + 1] == -1)
            dis[ux][uy][k + 1] = dis[ux][uy][k] + 1, bfs.push(state(ux, uy, k + 1));
        for(int i = 0; i < 4; i++){
            int vx = ux + skip[i][ux][uy] * adjR[i], vy = uy + skip[i][ux][uy] * adjC[i];
            if(vx >= 0 && vx < n && vy >= 0 && vy < m && dis[vx][vy][k] == -1)
                dis[vx][vy][k] = dis[ux][uy][k] + 1, bfs.push(state(vx, vy, k));
        }
    }
}