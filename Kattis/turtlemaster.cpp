#include <bits/stdc++.h>
using namespace std;

// Turtle Master

int dirR[4]{0, 1, 0, -1};
int dirC[4]{1, 0, -1, 0};

char grid[13][13];
int x = 7, y = 0, d = 0;

bool solve(string ins){
    for(char c : ins){
        if(c == 'F'){
            int nx = x + dirR[d], ny = y + dirC[d];
            if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && grid[nx][ny] != 'C' && grid[nx][ny] != 'I')
                x = nx, y = ny;
            else return false;
        }
        else if(c == 'R')
            d = (d + 1) % 4;
        else if(c == 'L')
            d = (d + 3) % 4;
        else if(c == 'X'){
            int nx = x + dirR[d], ny = y + dirC[d];
            if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && grid[nx][ny] == 'I')
                grid[nx][ny] = '.';
            else return false;
        }
    }
    return grid[x][y] == 'D';
}


int main(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> grid[i][j];
    string ins;
    cin >> ins;
    cout << (solve(ins) ? "Diamond!" : "Bug!") << endl;
}