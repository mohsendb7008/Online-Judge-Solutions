#include <bits/stdc++.h>
using namespace std;

// Piano Lessons

int n, m, match[1003], vis[1003];
vector<int> adj[1003];

bool augment(int l){
    if(vis[l])
        return 0;
    vis[l] = 1;
    for(int r : adj[l])
        if(match[r] == -1 || augment(match[r])){
            match[r] = l;
            return 1;
        }
    return 0;
}

int main(){
    cin >> n >> m;
    int d, x;
    for(int i = 0; i < n; i++){
        cin >> d;
        while(d--)
            cin >> x, adj[i].push_back(x-1);
    }
    fill_n(match, m, -1);
    int mcbm = 0;
    for(int i = 0; i < n; i++)
        fill_n(vis, n, 0), mcbm += augment(i);
    cout << mcbm << endl;
}