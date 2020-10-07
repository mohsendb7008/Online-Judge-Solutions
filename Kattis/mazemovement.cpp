#include <bits/stdc++.h>
using namespace std;

// Maze Movement

int gcd(int a, int b){
    if(!a)
        return b;
    return gcd(b % a, a);
}

int n, a[1003], c[1003][1003], flow[1003][1003], par[1003];
vector<int> adj[1003];

int augment(){
    fill_n(par, n, -1);
    par[0] = -2;
    queue<pair<int, int>> bfs;
    bfs.push({0, INT_MAX});
    while(!bfs.empty()){
        int u = bfs.front().first, f = bfs.front().second;
        bfs.pop();
        if(u == n-1)
            return f;
        for(int v : adj[u])
            if(par[v] == -1 && c[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push({v, min(f, c[u][v] - flow[u][v])});
    }
    return 0;
}

int max_flow(){
    int ans = 0;
    while(1){
        int f = augment();
        if(!f)
            break;
        ans += f;
        int it = n-1;
        while(it != 0){
            flow[par[it]][it] += f;
            flow[it][par[it]] -= f;
            it = par[it];
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            int g = gcd(a[i], a[j]);
            if(g > 1)
                c[i][j] = g, c[j][i] = g, adj[i].push_back(j), adj[j].push_back(i);
        }
    cout << max_flow() << endl;
}