#include <bits/stdc++.h>
using namespace std;

// Pear-wise Voting

int n, m;
vector<int> adj[28];
pair<int, string> ballots[20003];

bool vis[28];
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> ballots[i].first >> ballots[i].second;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            int sumi = 0, sumj = 0;
            for(int k = 0; k < m; k++){
                if(ballots[k].second.find('A' + i) < ballots[k].second.find('A' + j))
                    sumi += ballots[k].first;
                else sumj += ballots[k].first;
            }
            if(sumi > sumj)
                adj[i].push_back(j);
            else adj[j].push_back(i);
        }
    for(int i = 0; i < n; i++){
        fill_n(vis, n, false);
        dfs(i);
        cout << char('A' + i) << ": " << (count(vis, vis+n, true) == n ? "can win" : "can't win") << endl;
    }
}