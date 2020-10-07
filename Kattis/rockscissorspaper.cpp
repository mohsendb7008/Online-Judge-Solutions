#include <bits/stdc++.h>
using namespace std;

// Rock, Scissors, Paper

int n, m, d;
char grid[103][103], tmp[103][103];
int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> d;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j];
        while(d--){
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++){
                    char self = grid[i][j];
                    char opp;
                    if(self == 'S')
                        opp = 'R';
                    else if(self == 'P')
                        opp = 'S';
                    else opp = 'P';
                    bool found = false;
                    for(int k = 0; k < 4; k++){
                        int x = i + adjR[k], y = j + adjC[k];
                        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == opp){
                            found = true;
                            break;
                        }
                    }
                    tmp[i][j] = found ? opp : self;
                }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    grid[i][j] = tmp[i][j];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << grid[i][j];
            cout << endl;
        }
        if(!t)
            cout << endl;
    }
}