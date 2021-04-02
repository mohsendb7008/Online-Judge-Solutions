#include <bits/stdc++.h>
using namespace std;

// Jogging Trails

const int inf = INT_MAX;

int n, m, deg[15 + 3], floyd[15 + 3][15 + 3], dp[(1 << 15) + 3];

int main(){
    while(cin >> n){
        if(!n)
            break;
        for(int i = 0; i < n; i++){
            deg[i] = 0;
            for(int j = 0; j < n; j++)
                floyd[i][j] = inf;
            floyd[i][i] = 0;
        }
        cin >> m;
        int x, y, w, ans = 0;
        while(m--){
            cin >> x >> y >> w, x--, y--, ans += w, deg[x]++, deg[y]++;
            floyd[x][y] = min(floyd[x][y], w), floyd[y][x] = min(floyd[y][x], w);
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(floyd[i][k] != inf && floyd[k][j] != inf)
                        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
        int full = 0;
        for(int i = 0; i < n; i++)
            if(deg[i] % 2)
                full += (1 << i);
        for(int mask = 1; mask <= full; mask++){
            dp[mask] = inf;
            for(int i = 0; i < n; i++)
                if(mask & (1 << i))
                    for(int j = 0; j < n; j++)
                        if(j != i && (mask & (1 << j))){
                            int subp = dp[mask - (1 << i) - (1 << j)];
                            if(subp != inf && floyd[i][j] != inf)
                                dp[mask] = min(dp[mask], subp + floyd[i][j]);
                        }
        }
        cout << ans + dp[full] << endl;
    }
}