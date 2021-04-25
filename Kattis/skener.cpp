#include <bits/stdc++.h>
using namespace std;

// Skener

int r, c, zr, zc;
char g[53][53];

int main(){
    cin >> r >> c >> zr >> zc;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> g[i][j];
    for(int i = 0; i < r * zr; i++){
        for(int j = 0; j < c * zc; j++)
            cout << g[i / zr][j / zc];
        cout << '\n';
    }
}