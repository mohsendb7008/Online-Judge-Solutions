#include <bits/stdc++.h>
using namespace std;

// Robot Turtles

int adjR[4]{0, 1, 0, -1};
int adjC[4]{1, 0, -1, 0};

char grid[10][10];
pair<int, int> src, dst;
int cnt = 0;
map<pair<int, int>, int> ice;

struct state{
    int x, y, d, ices;

    state(){
        this->x = -1;
    }

    state(int x, int y, int d, int ices){
        this->x = x;
        this->y = y;
        this->d = d;
        this->ices = ices;
    }

    bool operator==(const state& o) const{
        return this->x == o.x && this->y == o.y && this->d == o.d && this->ices == o.ices;
    }
};

state par[10][10][5][(1 << 10) + 3];
queue<state> bfs;

state it(-2, 0, 0, 0);
vector<char> ans;

int main(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'T')
                src = {i, j};
            if(grid[i][j] == 'D')
                dst = {i, j};
            if(grid[i][j] == 'I')
                ice[{i, j}] = cnt++;
        }
    par[src.first][src.second][0][(1 << cnt) - 1] = state(-2, 0, 0, 0);
    state s(src.first, src.second, 0, (1 << cnt) - 1);
    bfs.push(s);
    while(!bfs.empty()){
        state u = bfs.front();
        bfs.pop();
        if(u.x == dst.first && u.y == dst.second){
            it = u;
            break;
        }
        // F
        int x = u.x + adjR[u.d], y = u.y + adjC[u.d];
        if(x >= 0 && x < 8 && y >= 0 && y < 8 && grid[x][y] != 'C' && (grid[x][y] != 'I' || !((1 << ice[{x, y}]) & u.ices)) && par[x][y][u.d][u.ices].x == -1)
            par[x][y][u.d][u.ices] = u, bfs.push(state(x, y, u.d, u.ices));
        // R
        if(par[u.x][u.y][(u.d + 1) % 4][u.ices].x == -1)
            par[u.x][u.y][(u.d + 1) % 4][u.ices] = u, bfs.push(state(u.x, u.y, (u.d + 1) % 4, u.ices));
        // L
        if(par[u.x][u.y][(u.d + 3) % 4][u.ices].x == -1)
            par[u.x][u.y][(u.d + 3) % 4][u.ices] = u, bfs.push(state(u.x, u.y, (u.d + 3) % 4, u.ices));
        // X
        if(x >= 0 && x < 8 && y >= 0 && y < 8 && grid[x][y] == 'I' && ((1 << ice[{x, y}]) & u.ices))
            par[u.x][u.y][u.d][u.ices - (1 << ice[{x, y}])] = u, bfs.push(state(u.x, u.y, u.d, u.ices - (1 << ice[{x, y}])));
    }
    if(it.x == -2)
        cout << "no solution" << endl;
    else{
        while(!(it == s)){
            state pr = par[it.x][it.y][it.d][it.ices];
            if(it.x != pr.x || it.y != pr.y)
                ans.push_back('F');
            else if(it.d == (pr.d + 1) % 4)
                ans.push_back('R');
            else if(it.d == (pr.d + 3) % 4)
                ans.push_back('L');
            else if(it.ices != pr.ices)
                ans.push_back('X');
            it = pr;
        }
        reverse(ans.begin(), ans.end());
        for(char c : ans)
            cout << c;
        cout << endl;
    }
}