#include <bits/stdc++.h>
using namespace std;

int n, h[1003][1003], vis[1003][1003], top, bottom;

int adjR[8]{0, 0, -1, 1, 1, 1, -1, -1};
int adjC[8]{1, -1, 0, 0, 1, -1, 1, -1};

void dfs(int i, int j){
    vis[i][j] = 1;
    for(int k = 0; k < 8; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < n){
            if(h[x][y] == h[i][j] && !vis[x][y])
                dfs(x, y);
            if(h[x][y] > h[i][j])
                top = 0;
            if(h[x][y] < h[i][j])
                bottom = 0; 
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> h[i][j];
    int tops = 0, bottoms = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(!vis[i][j])
                top = 1, bottom = 1, dfs(i, j), tops += top, bottoms += bottom;
    cout << tops << " " << bottoms << endl;
}