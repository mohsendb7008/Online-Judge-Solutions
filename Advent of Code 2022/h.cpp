#include <iostream>
using namespace std;

char g[1003][1003];
const int n = 99;

int adjR[4]{0, 0, 1, -1};
int adjC[4]{1, -1, 0, 0};

inline bool visible(int i, int j){
    for(int k = 0; k < 4; k++){
        bool vis = 1;
        int x = i + adjR[k];
        int y = j + adjC[k];
        while(x >= 0 && x < n && y >= 0 && y < n){
            if(g[x][y] >= g[i][j]){
                vis = 0;
                break;
            }
            x += adjR[k];
            y += adjC[k];
        }
        if(vis){
            return 1;
        }
    }
    return 0;
}

int main(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans += visible(i, j);
        }
    }
    cout << ans << endl;
}