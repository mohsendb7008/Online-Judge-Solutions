#include <bits/stdc++.h>
using namespace std;

// The Grand Dinner

int m, n;
pair<int, int> teams[73];
pair<int, int> tables[53];

vector<int> arrangements[73];

int main(){
    while(1){
        cin >> m >> n;
        if(m + n == 0)
            break;
        for(int i = 0; i < m; i++)
            cin >> teams[i].first, teams[i].second = i;
        sort(teams, teams+m, greater<pair<int, int>>());
        for(int i = 0; i < n; i++)
            cin >> tables[i].first, tables[i].second = i;
        bool can = true;
        for(int i = 0; i < m; i++){
            arrangements[teams[i].second].clear();
            sort(tables, tables+n, greater<pair<int, int>>());
            int mem = teams[i].first;
            if(mem > n){
                can = false;
                break;
            }
            for(int j = 0; j < mem; j++){
                if(!tables[j].first){
                    can = false;
                    break;
                }
                tables[j].first--;
                arrangements[teams[i].second].push_back(tables[j].second+1);
            }
        }
        if(can){
            cout << 1 << endl;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < arrangements[i].size()-1; j++)
                    cout << arrangements[i][j] << " ";
                cout << arrangements[i][arrangements[i].size()-1] << endl;
            }
        }
        else cout << 0 << endl;
    }
}