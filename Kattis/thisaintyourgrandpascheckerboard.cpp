#include <bits/stdc++.h>
using namespace std;

// This Ain't Your Grandpa's Checkerboard

int n, rw[24], rb[24], cw[24], cb[24];
char g[24][24];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
            if(g[i][j] == 'W')
                rw[i]++, cw[j]++;
            else if(g[i][j] == 'B')
                rb[i]++, cb[j]++;
        }
    for(int i = 0; i < n; i++)
        if(rw[i] != rb[i] || cw[i] != cb[i]){
            cout << 0 << endl;
            return 0;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(i+2 < n && g[i][j] == g[i+1][j] && g[i+1][j] == g[i+2][j]){
                cout << 0 << endl;
                return 0;
            }
            if(j+2 < n && g[i][j] == g[i][j+1] && g[i][j+1] == g[i][j+2]){
                cout << 0 << endl;
                return 0;
            }
        }
    cout << 1 << endl;
}