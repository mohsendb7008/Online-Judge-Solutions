#include <bits/stdc++.h>
using namespace std;

// Vin Diagrams

int n, m;
char grid[103][103], gridA[103][103], gridB[103][103];
bool vis[103][103], insideA[103][103], insideB[103][103];

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

void dfsa(int i, int j, int k){
    vis[i][j] = true, gridA[i][j] = 'X';
    int nadj = 0;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 'X')
            nadj++;
    }
    if(nadj == 4)
        dfsa(i + adjR[k], j + adjC[k], k);
    else for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 'X' && !vis[x][y])
            dfsa(x, y, k);
    }
}

void dfsb(int i, int j, int k){
    vis[i][j] = true, gridB[i][j] = 'X';
    int nadj = 0;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 'X')
            nadj++;
    }
    if(nadj == 4)
        dfsb(i + adjR[k], j + adjC[k], k);
    else for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 'X' && !vis[x][y])
            dfsb(x, y, k);
    }
}

bool p;
void dfs2a(int i, int j){
    vis[i][j] = true;
    int nadj = 0;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m){
            nadj++;
            if(gridA[x][y] == '.' & !vis[x][y])
                dfs2a(x, y);
        }
    }
    if(nadj != 4)
        p = false;
}

void dfs2b(int i, int j){
    vis[i][j] = true;
    int nadj = 0;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m){
            nadj++;
            if(gridB[x][y] == '.' & !vis[x][y])
                dfs2b(x, y);
        }
    }
    if(nadj != 4)
        p = false;
}

void dfs3a(int i, int j){
    insideA[i][j] = true;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && gridA[x][y] == '.' && !insideA[x][y])
            dfs3a(x, y);
    }
}

void dfs3b(int i, int j){
    insideB[i][j] = true;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && gridB[x][y] == '.' && !insideB[x][y])
            dfs3b(x, y);
    }
}


int main(){
    cin >> n >> m;
    int xa, ya, xb, yb;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> grid[i][j], vis[i][j] = false;
            gridA[i][j] = gridB[i][j] = '.';
            insideA[i][j] = insideB[i][j] = false; 
            if(grid[i][j] == 'A')
                xa = i, ya = j;
            if(grid[i][j] == 'B')
                xb = i, yb = j;
        }
    grid[xa][ya] = grid[xb][yb] = 'X';
    dfsa(xa, ya, -1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            vis[i][j] = false;
    dfsb(xb, yb, -1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)  
            vis[i][j] = false;
    int ci, cj;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(gridA[i][j] == '.' && !vis[i][j]){
                p = true;
                dfs2a(i, j);
                if(p){
                    ci = i, cj = j;
                    break;
                }
            }
    dfs3a(ci, cj);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)  
            vis[i][j] = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(gridB[i][j] == '.' && !vis[i][j]){
                p = true;
                dfs2b(i, j);
                if(p){
                    ci = i, cj = j;
                    break;
                }
            }
    dfs3b(ci, cj);
    // cerr << "A:" << endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++)
    //         cerr << char(gridA[i][j] == 'X' ? 'X' : insideA[i][j] + '0');
    //     cerr << endl;
    // }
    // cerr << "B:" << endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++)
    //         cerr << char(gridB[i][j] == 'X' ? 'X' : insideB[i][j] + '0');
    //     cerr << endl;
    // }
    int ansU = 0, ansA = 0, ansB = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(insideA[i][j] && insideB[i][j])
                ansU++;
            if(insideA[i][j] && gridB[i][j] == '.')
                ansA++;
            if(insideB[i][j] && gridA[i][j] == '.')
                ansB++;
        }
    cout << ansA - ansU << " " << ansB - ansU << " " << ansU << endl;
}