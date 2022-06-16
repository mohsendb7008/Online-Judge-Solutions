#include <bits/stdc++.h>
using namespace std;

int mat[1003][1003];

int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        mat[u][v] = 1, mat[v][u] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
}