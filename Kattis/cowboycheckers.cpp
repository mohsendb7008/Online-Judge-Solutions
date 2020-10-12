#include <bits/stdc++.h>
using namespace std;

// Cowboy Checkers

map<string, pair<int, int>> checker{
    {"7a", {0, 0}},
    {"7d", {0, 3}},
    {"7g", {0, 6}},
    {"6b", {1, 1}},
    {"6d", {1, 3}},
    {"6f", {1, 5}},
    {"5c", {2, 2}},
    {"5d", {2, 3}},
    {"5e", {2, 4}},
    {"4a", {3, 0}},
    {"4b", {3, 1}},
    {"4c", {3, 2}},
    {"4e", {3, 4}},
    {"4f", {3, 5}},
    {"4g", {3, 6}},
    {"3c", {4, 2}},
    {"3d", {4, 3}},
    {"3e", {4, 4}},
    {"2b", {5, 1}},
    {"2d", {5, 3}},
    {"2f", {5, 5}},
    {"1a", {6, 0}},
    {"1d", {6, 3}},
    {"1g", {6, 6}}
};

vector<string> mills{
    "7a7d7g4b4c4a..",
    "7a7d7g1d1g4a1a",
    "7a7d7g6b6f6d..",
    "7a7d7g5c5e6d5d",
    "7a7d7g4e4f4g..",
    "7a7d7g1a1d4g1g",
    "6b6d6f4a4c4b..",
    "6b6d6f2d2f4b2b",
    "6b6d6f7a7g7d..",
    "6b6d6f5c5e5d..",
    "6b6d6f4e4g4f..",
    "6b6d6f2b2d4f2f",
    "5c5d5e4a4b4c..",
    "5c5d5e3d3e4c3c",
    "5c5d5e6b6f6d..",
    "5c5d5e7a7g6d7d",
    "5c5d5e4f4g4e..",
    "5c5d5e3c3d4e3e",
    "4a4b4c7d7g7a..",
    "4a4b4c1d1g1a..",
    "4a4b4c6d6f6b..",
    "4a4b4c2d2f2b..",
    "4a4b4c5d5e5c..",
    "4a4b4c3d3e3c.."
};

char grid[10][10], tmp[10][10];

void rotate(){
    int cnt = 0;
    for(int j = 0; j < 7; j++)
        for(int i = 6; i >= 0; i--)
            tmp[cnt / 7][cnt % 7] = grid[i][j], cnt++;
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            grid[i][j] = tmp[i][j];
}

int main(){
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            cin >> grid[i][j];
    for(int dir = 0; dir < 4; dir++){
        for(string mill : mills){
            bool ans = true;
            for(int i = 0; i < 5; i++){
                pair<int, int> p = checker[mill.substr(2 * i, 2)];
                if(grid[p.first][p.second] != 'W'){
                    ans = false;
                    break;
                }
            }
            if(!ans)
                continue;
            for(int i = 5; i < 7; i++){
                string s = mill.substr(2 * i, 2);
                if(s == "..")
                    continue;
                pair<int, int> p = checker[s];
                if(grid[p.first][p.second] != '.'){
                    ans = false;
                    break;
                }
            }
            if(!ans)
                continue;
            cout << "double mill" << endl;
            return 0;
        }
        rotate(); 
    }
    cout << "no double mill" << endl;
}