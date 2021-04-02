#include <bits/stdc++.h>
using namespace std;

// Molekule

int n;
pair<int, int> e[100003];
vector<int> adj[100003];
int color[100003];

void dfs(int u, int p, int c){
    color[u] = c;
    for(int v : adj[u])
        if(v != p)
           dfs(v, u, 1-c); 
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++)
        cin >> e[i].first >> e[i].second, e[i].first--, e[i].second--, adj[e[i].first].push_back(e[i].second), adj[e[i].second].push_back(e[i].first);
    dfs(0, -1, 0);
    for(int i = 0; i < n-1; i++)
        cout << color[e[i].first] << endl;
}