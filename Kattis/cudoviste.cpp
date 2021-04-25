#include <bits/stdc++.h>
using namespace std;

// Cudoviste

int r, c, ans[5];
char g[53][53];

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> g[i][j];
    for(int i = 0; i < r-1; i++)
        for(int j = 0; j < c-1; j++){
            if(g[i][j] == '#' || g[i+1][j] == '#' || g[i][j+1] == '#' || g[i+1][j+1] == '#')
                continue;
            int squashes = 0;
            if(g[i][j] == 'X')
                squashes++;
            if(g[i+1][j] == 'X')
                squashes++;
            if(g[i][j+1] == 'X')
                squashes++;
            if(g[i+1][j+1] == 'X')
                squashes++;
            ans[squashes]++;
        }
    for(int i = 0; i < 5; i++)
        cout << ans[i] << '\n';
}