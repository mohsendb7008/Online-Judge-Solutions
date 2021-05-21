#include <bits/stdc++.h>
using namespace std;

int n, t[33], vis[303][303][33][11];
set<pair<int, int>> ans;

int adjR[8]{-1, -1, 0, 1, 1, 1, 0, -1};
int adjC[8]{0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int x, int y, int i, int d){
    if(vis[x+150][y+150][i][d])
        return;
    vis[x+150][y+150][i][d] = 1;
    for(int j = 0; j < t[i]; j++)
        ans.insert({x+j*adjR[d], y+j*adjC[d]});
    if(i == n-1)
        return;
    int px = x+(t[i]-1)*adjR[d], py = y+(t[i]-1)*adjC[d];
    dfs(px+adjR[(d+7)%8], py+adjC[(d+7)%8], i+1, (d+7)%8);
    dfs(px+adjR[(d+1)%8], py+adjC[(d+1)%8], i+1, (d+1)%8);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    dfs(0, 0, 0, 0);
    cout << ans.size() << endl;
}