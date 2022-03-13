// Okvir

#include <bits/stdc++.h>
using namespace std;

int n, m, u, l, r, d;
char g[13][13];

int main(){
    cin >> n >> m >> u >> l >> r >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < n + u + d; i++){
        for(int j = 0; j < m + l + r; j++){
            if(i >= u && i < u + n && j >= l && j < l + m){
                cout << g[i - u][j - l];
            }
            else{
                cout << (((i + j) % 2) ? '.' : '#');
            }
        }
        cout << endl;
    }
}