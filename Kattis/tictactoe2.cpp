#include <bits/stdc++.h>
using namespace std;

// Tic Tac Toe

char grid[3][3];

bool win(char c){
    for(int i = 0; i < 3; i++)
        if(grid[i][0] == c && grid[i][1] == c && grid[i][2] == c)
            return true;
    for(int j = 0; j < 3; j++)
        if(grid[0][j] == c && grid[1][j] == c && grid[2][j] == c)
            return true;
    if(grid[0][0] == c && grid[1][1] == c && grid[2][2] == c)
        return true;
    if(grid[0][2] == c && grid[1][1] == c && grid[2][0] == c)
        return true;
    return false;
}

bool solve(){
    int x = 0, o = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == 'X')
                x++;
            if(grid[i][j] == 'O')
                o++;
        }
    if(!(x == o || x == o + 1))
        return false;
    bool winx = win('X'), wino = win('O');
    if(winx && wino)
        return false;
    if(winx && x == o)
        return false;
    if(wino && x == o + 1)
        return false;
    return true;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                cin >> grid[i][j];
        cout << (solve() ? "yes" : "no") << endl;
    }
}