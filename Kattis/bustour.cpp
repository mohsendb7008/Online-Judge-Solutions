#include <bits/stdc++.h>
using namespace std;

// Bus Tour

int n, m, u, v, t;
int floyd[20][20];

int tsp2[1<<20][2][20];

int ctsp2(int mask, int origin, int node){
    if(tsp2[mask][origin][node] != -1)
        return tsp2[mask][origin][node];
    int co = origin ? n-1 : 0;
    if(node == co)
        return tsp2[mask][origin][node] = 0;
    if(mask - (1<<node) == (1 << co))
        return tsp2[mask][origin][node] = floyd[co][node];
    int ans = INT_MAX;
    for(int prevy = 0; prevy < n; prevy++)
        if(prevy != node && prevy != co && (mask & (1<<prevy)))
            ans = min(ans, floyd[prevy][node] + ctsp2(mask-(1<<node), origin, prevy));
    return tsp2[mask][origin][node] = ans;
}

int tsp[1<<20][20];

int ctsp(int mask, int node){
    if(tsp[mask][node] != -1)
        return tsp[mask][node];
    int ans = INT_MAX;
    int ones = 0;
    if(mask == 1 << node){
        ans =  floyd[0][node+1];
        ones = 1;
    }
    else for(int prevy = 0; prevy < n-1; prevy++)
        if(mask & (1<<prevy)){
            ones++;
            if(prevy == node)
                continue;
            ans = min(ans, floyd[prevy+1][node+1] + ctsp(mask-(1<<node), prevy));
        }
    if(ones == (n-2)/2){
        int add = INT_MAX;
        int rmask = (mask<<1) + (1<<(n-1)); 
        int lmask = (1<<n) - 1 - rmask;
        for(int i = 1; i < n; i++)
            if(lmask & (1<<i))
                for(int j = 0; j < n-1; j++)
                    if(rmask & (1<<j))
                        add = min(add, ctsp2(lmask, 0, i) + floyd[i][j] + ctsp2(rmask, 1, j));
        ans += add;
    }
    return tsp[mask][node] = ans; 
}



int main(){
    int test = 1;
    while(cin >> n >> m){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                floyd[i][j] = i == j ? 0 : INT_MAX;
        while(m--){
            cin >> u >> v >> t;
            floyd[u][v] = t;
            floyd[v][u] = t; 
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(floyd[i][k] != INT_MAX && floyd[k][j] != INT_MAX)
                        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
        if(n == 3){
            cout << "Case " << test++ << ": " << 2 * (floyd[0][1] + floyd[1][2]) << endl;
            continue;
        }
        for(int i = 0; i < (1<<n); i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < n; k++)
                    tsp2[i][j][k] = -1;
        for(int i = 0; i < (1<<(n-1)); i++)
            for(int j = 0; j < n-1; j++)
                tsp[i][j] = -1;
        cout << "Case " << test++ << ": " << ctsp((1<<(n-1))-1, n-2) << endl;
    }
}