#include <bits/stdc++.h>
using namespace std;

// Mirror Images

int n, m;
char g[23][23];

int main(){
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j];
        cout << "Test " << k << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << g[n-1-i][m-1-j];
            cout << endl;
        }
    }
}