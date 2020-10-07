#include <bits/stdc++.h>
using namespace std;

// Flood-It

int t, n;
char grid[23][23];
bool vis[23][23], tvis[23][23];
int color[9];

int adjR[4]{0, 0, 1, -1};
int adjC[4]{1, -1, 0, 0};

int cc, cnt;
void dfs(int i, int j){
    tvis[i][j] = true, cnt++;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < n && !tvis[x][y] && grid[x][y] == '0' + cc)
            dfs(x, y);
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j], tvis[i][j] = false;
        cc = grid[0][0] - '0', cnt = 0;
        dfs(0, 0);
        int nvis = cnt;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                vis[i][j] = tvis[i][j];
        fill(color+1, color+7, 0);
        int ans = 0;
        while(nvis < n * n){
            int maxn = INT_MIN, co;
            for(int c = 1; c <= 6; c++){
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                        tvis[i][j] = vis[i][j];
                cc = c, cnt = 0;
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                        if(tvis[i][j]){
                            for(int k = 0; k < 4; k++){
                                int x = i + adjR[k], y = j + adjC[k];
                                if(x >= 0 && x < n && y >= 0 && y < n && !tvis[x][y] && grid[x][y] == '0' + c)
                                    dfs(x, y);
                            }
                        }
                if(cnt > maxn)
                    maxn = cnt, co = c;
            }
            nvis += maxn, ans++, color[co]++;
            for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                        tvis[i][j] = vis[i][j];
            cc = co, cnt = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(tvis[i][j]){
                        for(int k = 0; k < 4; k++){
                            int x = i + adjR[k], y = j + adjC[k];
                            if(x >= 0 && x < n && y >= 0 && y < n && !tvis[x][y] && grid[x][y] == '0' + cc)
                                dfs(x, y);
                        }
                    }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    vis[i][j] = tvis[i][j];
        }
        cout << ans << endl;
        for(int c = 1; c <= 6; c++)
            cout << color[c] << " ";
        cout << endl;
    }
}