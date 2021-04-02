#include <bits/stdc++.h>
using namespace std;

// Faulty Robot

int n, m;
vector<int> adj[1003];
vector<int> adjf[1003]; 

set<int> stops;
bool visited[1003][3];

void dfs(int node, int buggy){
    if(visited[node][buggy])
        return;
    visited[node][buggy] = true;
    if(adjf[node].empty())
        stops.insert(node);
    for(int adj : adjf[node])
        dfs(adj, buggy);
    if(buggy){
        for(int adj : adj[node])
            dfs(adj, false);
    }
}

int main(){
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m ; i++){
        cin >> x >> y;
        if(x < 0){
            x *= -1;
            adjf[x-1].push_back(y-1);
        }else{
            adj[x-1].push_back(y-1);
        }
    }
    for(int i = 0; i < n; i++){
        visited[i][0] = false;
        visited[i][1] = false;
    }
    dfs(0, true);
    cout << stops.size() << endl;
}