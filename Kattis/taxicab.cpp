#include <bits/stdc++.h>
using namespace std;

// Taxi Cab Scheme

int m, n, t[503], x1[503], y11[503], x2[503], y2[503], vis[503], match[503];
vector<int> adj[503];

bool aug(int l){
    if(vis[l])
        return 0;
    vis[l] = 1;
    for(int r : adj[l])
        if(match[r] == -1 || aug(match[r])){
            match[r] = l;
            return 1;
        }
    return 0;
}

int main(){
    scanf("%d", &m);
    while(m--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int h, m;
            scanf("%02d:%02d %d %d %d %d", &h, &m, x1 + i, y11 + i, x2 + i, y2 + i);
            t[i] = 60 * h + m;
            adj[i].clear();
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j){
                    int d = abs(x1[i] - x2[i]) + abs(y11[i] - y2[i]) + abs(x2[i] - x1[j]) + abs(y2[i] - y11[j]);
                    if(t[i] + d < t[j])
                        adj[i].push_back(j);
                }
        fill_n(match, n, -1);
        int mcbm = 0;
        for(int i = 0; i < n; i++)
            fill_n(vis, n, 0), mcbm += aug(i);
        printf("%d\n", n - mcbm);
    }
}