// Nine Knights

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++){
            char c;
            cin >> c;
            if(c == 'k')
                v.push_back({i, j});
        }
    if (v.size() != 9){
        cout << "invalid" << endl;
        return 0;
    }
    for(int i = 0; i < 9; i++)
        for(int j = i + 1; j < 9; j++){
            int dx = abs(v[i].first - v[j].first);
            int dy = abs(v[i].second - v[j].second);
            if((dx == 2 && dy == 1) || (dx == 1 && dy == 2)){
                cout << "invalid" << endl;
                return 0;
            }
        }
    cout << "valid" << endl;
}