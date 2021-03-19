#include <bits/stdc++.h>
using namespace std;

// A Mazing!

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};
string cmd[4]{"right", "left", "up", "down"};
int antonym[4]{1, 0, 3, 2};

set<pair<int, int>> vis;

bool dfs(int i, int j){
    vis.insert({i, j});
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(vis.find({x, y}) != vis.end())
            continue;
        string response;
        cout << cmd[k] << endl, cout.flush();
        cin >> response;
        if(response == "wall")
            continue;
        if(response == "solved")
            return true;
        if(response == "ok"){
            if(dfs(x, y))
                return true;
            cout << cmd[antonym[k]] << endl, cout.flush();
            cin >> response;
            assert(response == "ok");
        }
    }
    return false;
}

int main(){
    if(!dfs(0, 0))
        cout << "no way out" << endl, cout.flush();
}