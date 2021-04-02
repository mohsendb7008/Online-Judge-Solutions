#include <bits/stdc++.h>
using namespace std;

// All Pairs Shortest Path

#define num long long int
#define inf INT_MAX

int n, m, q;
num floyd[153][153];

int main(){
    while(1){
        cin >> n >> m >> q;
        if(!(n + m + q))
            break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                floyd[i][j] = i == j ? 0 : inf;
        while(m--){
            int x, y;
            num w;
            cin >> x >> y >> w;
            floyd[x][y] = min(floyd[x][y], w);
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(floyd[i][k] != inf && floyd[k][j] != inf)
                        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    if(floyd[i][k] != inf && floyd[k][j] != inf && floyd[k][k] < 0)
                        floyd[i][j] = -inf;
        while(q--){
            int u, v;
            cin >> u >> v;
            if(floyd[u][v] == -inf)
                cout << "-Infinity " << endl;
            else if(floyd[u][v] == inf)
                cout << "Impossible" << endl;
            else
                cout << floyd[u][v] << endl;
        }
    }
}