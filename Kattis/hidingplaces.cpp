#include <bits/stdc++.h>
using namespace std;

// Hiding Places

int adjR[8]{1, 2, 1, 2, -1, -2, -1, -2};
int adjC[8]{-2, -1, 2, 1, -2, -1, 2, 1};

bool cmp(pair<char, char> & f, pair<char, char> & s){
    if(f.second == s.second)
        return f.first < s.first;
    return f.second > s.second;
}

int dis[11][11];
queue<pair<int, int>> bfs;

int main(){
    int n;
    cin >> n;
    while(n--){
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                dis[i][j] = -1;
        string x;
        cin >> x;
        int sx = x[1] - '1', sy = x[0] - 'a';
        dis[sx][sy] = 0;
        bfs.push({sx, sy});
        int ans = 0;
        while(!bfs.empty()){
            pair<int, int> u = bfs.front();
            bfs.pop();
            for(int k = 0; k < 8; k++){
                int x = u.first + adjR[k], y = u.second + adjC[k];
                if(x >= 0 && x < 8 && y >= 0 && y < 8 && dis[x][y] == -1)
                    dis[x][y] = dis[u.first][u.second] + 1, ans = max(ans, dis[x][y]), bfs.push({x, y});
            }
        }
        cout << ans << " ";
        vector<pair<char, char>> v;
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                if(dis[i][j] == ans)
                    v.push_back({'a' + j, '1' + i});
        sort(v.begin(), v.end(), cmp);
        for(pair<char, char> s : v)
            cout << s.first << s.second << " ";
        cout << endl;       
    }
}