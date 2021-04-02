#include <bits/stdc++.h>
using namespace std;

// Superdoku

int n, k, g[103][103];
set<int> tmp, cols[103];
vector<int> adj[103];
int vis[103], match[103];

bool aug(int l){
    if(vis[l])
        return 0;
    vis[l] = 1;
    for(int r : adj[l]){
        if(match[r] == -1 || aug(match[r])){
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    for(int i = 0; i < k; i++){
        tmp.clear();
        for(int j = 0; j < n; j++){
            if(tmp.find(g[i][j]) != tmp.end()){
                cout << "no" << endl;
                return 0;
            }
            tmp.insert(g[i][j]);
        }
    }
    for(int j = 0; j < n; j++){
        tmp.clear();
        for(int i = 0; i < k; i++){
            if(tmp.find(g[i][j]) != tmp.end()){
                cout << "no" << endl;
                return 0;
            }
            tmp.insert(g[i][j]);
        }
    }
    if(k < n){
        for(int i = 0; i < k; i++)
            for(int j = 0; j < n; j++)
                cols[j].insert(g[i][j]);
        for(int i = k; i < n; i++){
            for(int c = 1; c <= n; c++){
                adj[c].clear();
                for(int j = 0; j < n; j++)
                    if(cols[j].find(c) == cols[j].end())
                        adj[c].push_back(j);
            }
            fill_n(match, n, -1);
            for(int c = 1; c <= n; c++)
                fill_n(vis, n + 1, 0), aug(c);
            for(int j = 0; j < n; j++)
                g[i][j] = match[j], cols[j].insert(match[j]);
        }
    }
    cout << "yes" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}