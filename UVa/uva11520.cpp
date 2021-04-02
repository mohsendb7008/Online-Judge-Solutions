#include <bits/stdc++.h>
using namespace std;

// Fill the Square

int n;
char grid[13][13];

int adjR[4]{1, -1, 0, 0};
int adjC[4]{0, 0, 1, -1};

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '.'){
                    set<char> adjacents;
                    for(int k = 0; k < 4; k++){
                        int x = i + adjR[k];
                        int y = j + adjC[k];
                        if(x >= 0 && x < n && y >= 0 && y < n)
                            adjacents.insert(grid[x][y]);
                    }
                    for(char c = 'A'; c <= 'Z'; c++)
                        if(adjacents.find(c) == adjacents.end()){
                            grid[i][j] = c;
                            break;
                        }
                }
        cout << "Case " << test << ":" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << grid[i][j];
            cout << endl;
        }
    }
}