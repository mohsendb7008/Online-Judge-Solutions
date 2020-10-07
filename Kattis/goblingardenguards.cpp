#include <bits/stdc++.h>
using namespace std;

// Goblin Garden Guards

int goblins[10003][10003];

int main(){
    for(int i = 0; i <= 10000; i++)
        for(int j = 0; j <= 10000; j++)
            goblins[i][j] = 0;
    int g, x, y;
    cin >> g;
    while(g--){
        cin >> x >> y;
        goblins[x][y]++;
    }
    int m, r;
    cin >> m;
    while(m--){
        cin >> x >> y >> r;
        for(int i = max(x-r, 0); i <= min(x+r, 10000); i++)
            for(int j = max(y-r, 0); j <= min(y+r, 10000); j++){
                int deltax = i - x;
                int deltay = j - y;
                if(deltax * deltax + deltay * deltay <= r * r)
                    goblins[i][j] = 0;
            }
    }
    int ans = 0;
    for(int i = 0; i <= 10000; i++)
        for(int j = 0; j <= 10000; j++)
            ans += goblins[i][j];
    cout << ans << endl;
}