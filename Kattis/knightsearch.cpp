#include <bits/stdc++.h>
using namespace std;

// Knight Search

int n;
char grid[103][103];

char job[13] = "ICPCASIASG";
int adjR[8]{-1, 1, -1, 1, 2, -2, -2, 2};
int adjC[8]{2, -2, -2, 2, -1, 1, -1, 1};

bool solve(int x, int y, int i){
    if(i == 10)
        return true;
    for(int k = 0; k < 8; k++){
        int a = x + adjR[k], b = y + adjC[k];
        if(a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == job[i] && solve(a, b, i+1))
            return true;
    }
    return false;
}

int main(){
    cin >> n;
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            cin >> grid[x][y];
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            if(grid[x][y] == job[0] && solve(x, y, 1)){
                cout << "YES" << endl;
                return 0;
            }
    cout << "NO" << endl;
}