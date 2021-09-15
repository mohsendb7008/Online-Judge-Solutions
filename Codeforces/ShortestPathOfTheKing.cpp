#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;

int adjR[] {-1, +1, 0, 0, +1, -1, +1, -1};
int adjC[] {0, 0, +1, -1, -1, -1, +1, +1};
string rep[] {"D", "U", "R", "L", "LU", "LD", "RU", "RD"};

int dis[8][8], par[8][8];
queue<pair<int, int>> bfs;
vector<string> ans;

int main(){
    string s, t;
    cin >> s >> t;
    int si = s[1] - '1', sj = s[0] - 'a';
    int ti = t[1] - '1', tj = t[0] - 'a';
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            dis[i][j] = inf;
    dis[si][sj] = 0;
    bfs.push({si, sj});
    while(!bfs.empty()){
        auto u = bfs.front();
        bfs.pop();
        for(int k = 0; k < 8; k++){
            pair<int, int> v = {u.first + adjR[k], u.second + adjC[k]};
            if(v.first >= 0 && v.first < 8 && v.second >= 0 && v.second < 8 && dis[v.first][v.second] == inf)
                dis[v.first][v.second] = dis[u.first][u.second] + 1, par[v.first][v.second] = k, bfs.push(v);
        }
    }
    while(!(ti == si && tj == sj)){
        int k = par[ti][tj];
        ans.push_back(rep[k]);
        ti -= adjR[k], tj -= adjC[k];
    }
    cout << ans.size() << endl;
    for(auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << endl;
}