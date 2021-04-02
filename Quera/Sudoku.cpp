#include <bits/stdc++.h>
using namespace std;

int grid[9][9];
set<int> all{1, 2, 3, 4, 5, 6, 7, 8, 9}, domain[9][9];

bool forward_checking(int i, int j, int c, vector<pair<int, int>>& omits){
    for(int col = 0; col < 9; col++){
        if(col == j || grid[i][col])
            continue;
        if(domain[i][col].find(c) != domain[i][col].end()){
            if(domain[i][col].size() == 1)
                return false;
            omits.push_back({i, col});
        }
    }
    for(int row = 0; row < 9; row++){
        if(row == i || grid[row][j])
            continue;
        if(domain[row][j].find(c) != domain[row][j].end()){
            if(domain[row][j].size() == 1)
                return false;
            omits.push_back({row, j});
        }
    }
    int x = i - i % 3, y = j - j % 3;
    for(int a = 0; a < 3; a++)
        for(int b = 0; b < 3; b++){
            if((x + a == i && y + b == j) || grid[x + a][y + b])
                continue;
            if(domain[x + a][y + b].find(c) != domain[x + a][y + b].end()){
                if(domain[x + a][y + b].size() == 1)
                    return false;
                omits.push_back({x + a, y + b});
            }
        }
    return true;
}

bool track(int cnt){
    if(cnt == 81){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
        return true;
    }
    int i = cnt / 9, j = cnt % 9;
    for(int c : domain[i][j]){
        vector<pair<int, int>> omits;
        if(!forward_checking(i, j, c, omits))
            continue;
        grid[i][j] = c;
        for(auto p : omits)
            domain[p.first][p.second].erase(c);
        if(track(cnt + 1))
            return true;
        for(auto p : omits)
            domain[p.first][p.second].insert(c);
        grid[i][j] = 0;
    }
    return false;
}

int main(){
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            int x;
            cin >> x;
            if(x)
                domain[i][j].insert(x);
            else
                domain[i][j] = all;
        }
    if(!track(0))
        cout << "No solution exists" << endl;
}