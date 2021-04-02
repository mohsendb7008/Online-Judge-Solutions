#include <bits/stdc++.h>
using namespace std;

// Cross Country

#define inf INT_MAX

int n, s, d, g[1003][1003], dis[1003];

int main(){
    scanf("%d %d %d", &n, &s, &d);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    fill_n(dis, n, inf);
    dis[s] = 0;
    for(int _ = 0; _ < n-1; _++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j && dis[i] != inf)
                    dis[j] = min(dis[j], dis[i] + g[i][j]);
    printf("%d", dis[d]);
}