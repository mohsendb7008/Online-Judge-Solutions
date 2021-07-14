#include <bits/stdc++.h>
using namespace std;

int n, x[5003], y[5003], color[5003], cc, p2[5003];
vector<int> adj[5003];
bool bicolorable;

void dfs(int u, int c){
    color[u] = c;
    for(int v : adj[u]){
        if(color[v] == 2)
            dfs(v, 1 - c);
        else if(color[v] == c)
            bicolorable = false;
    }
}

bool judge(int d){
    fill_n(color, n, 2);
    cc = 0;
    for(int i = 0; i < n; i++)
        adj[i].clear();
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > d)
                adj[i].push_back(j), adj[j].push_back(i);
    bicolorable = true;
    for(int i = 0; i < n; i++)
        if(color[i] == 2)
            cc++, dfs(i, 0);
    return bicolorable;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int lo = 0, hi = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            hi = max(hi, abs(x[i] - x[j]) + abs(y[i] - y[j]));
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    judge(lo);
    p2[0] = 1;
    for(int i = 1; i <= cc; i++)
        p2[i] = (p2[i - 1] * 2) % 1000000007;
    cout << lo << endl;
    cout << p2[cc] << endl;
}