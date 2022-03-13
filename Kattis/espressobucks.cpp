// Espresso Bucks

#include <bits/stdc++.h>
using namespace std;

int n, m;
char g[103][103];

set<pair<int, int>> coffee_shops;

int adjR[4]{0, 0, 1, -1};
int adjC[4]{1, -1, 0, 0};

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '.'){
                bool has_adjacent_coffee_shop = false;
                for(int k = 0; k < 4; k++){
                    int x = i + adjR[k];
                    int y = j + adjC[k];
                    if(coffee_shops.find({x, y}) != coffee_shops.end()){
                        has_adjacent_coffee_shop = true;
                        break;
                    }
                }
                if(!has_adjacent_coffee_shop){
                    g[i][j] = 'E';
                    coffee_shops.insert({i, j});
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << g[i][j];
        }
        cout << endl;
    }
}
