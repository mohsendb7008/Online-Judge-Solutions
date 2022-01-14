// Fun House

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, dir;
char g[23][23];

int adjR[4]{0, 1, 0, -1};
int adjC[4]{1, 0, -1, 0};

inline bool on_edge(int i, int j){
    return i == 0 || i == n-1 || j == 0 || j == m-1;
}

int main(){
    int tc = 0;
    while(1){
        cin >> m >> n;
        if(!(m + n)){
            break;
        }
        tc++;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
                if(g[i][j] == '*'){
                    x = i;
                    y = j;
                    if(i == 0){
                        dir = 1;
                    }
                    else if(i == n-1){
                        dir = 3;
                    }
                    else if(j == 0){
                        dir = 0;
                    }
                    else if(j == m-1){
                        dir = 2;
                    }
                }
            }
        }
        x += adjR[dir];
        y += adjC[dir];
        while(!on_edge(x, y)){
            if(g[x][y] == '/'){
                if(dir == 0){
                    dir = 3;
                }
                else if(dir == 1){
                    dir = 2;
                }
                else if(dir == 2){
                    dir = 1;
                }
                else if(dir == 3){
                    dir = 0;
                }
            }
            else if(g[x][y] == '\\'){
                if(dir == 0){
                    dir = 1;
                }
                else if(dir == 1){
                    dir = 0;
                }
                else if(dir == 2){
                    dir = 3;
                }
                else if(dir == 3){
                    dir = 2;
                }
            }
            x += adjR[dir];
            y += adjC[dir];
        }
        g[x][y] = '&';
        cout << "HOUSE " << tc << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << g[i][j];
            }
            cout << endl;
        }
    }
}