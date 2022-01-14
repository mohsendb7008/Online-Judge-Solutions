// Touchscreen Keyboard

#include <bits/stdc++.h>
using namespace std;

string grid[3]{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
map<char, pair<int, int>> coordinates;

inline int dist(char p, char q){
    auto pc = coordinates[p];
    auto qc = coordinates[q];
    return abs(pc.first - qc.first) + abs(pc.second - qc.second);
}

int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < grid[i].size(); j++){
            coordinates[grid[i][j]] = {i, j};
        }
    }
    int t;
    cin >> t;
    while(t--){
        string w;
        cin >> w;
        int n;
        cin >> n;
        set<pair<int, string>> ans;
        while(n--){
            string e;
            cin >> e;
            int d = 0;
            for(int i = 0; i < w.size(); i++){
                d += dist(w[i], e[i]);
            }
            ans.insert({d, e});
        }
        for(auto it : ans){
            cout << it.second << " " << it.first << endl;
        }
    }
}