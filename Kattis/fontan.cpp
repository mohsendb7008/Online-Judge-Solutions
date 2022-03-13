// Fountain

#include <bits/stdc++.h>
using namespace std;

int n, m;
char g[53][53];
queue<pair<int, int>> water_queue;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    while(true){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 'V' && i + 1 < n && g[i+1][j] == '.'){
                    water_queue.push({i+1, j});
                }
                else if(g[i][j] == 'V' && i + 1 < n && g[i+1][j] == '#'){
                    if(j && g[i][j-1] == '.'){
                        water_queue.push({i, j-1});
                    }
                    if(j + 1 < m && g[i][j+1] == '.'){
                        water_queue.push({i, j+1});
                    }
                }
            }
        }
        if(water_queue.empty()){
            break;
        }
        while(!water_queue.empty()){
            auto u = water_queue.front();
            water_queue.pop();
            g[u.first][u.second] = 'V';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << g[i][j];
        }
        cout << endl;
    }
}