#include <bits/stdc++.h>
using namespace std;

// Units

int n;
string names[13];
map<string, int> id;
vector<pair<int, double>> adj[13];
double vis[13];
pair<double, int> units[13];

void dfs(int u, double mul){
    vis[u] = mul;
    for(auto v : adj[u])
        if(vis[v.first] == -1)
            dfs(v.first, vis[u] * v.second);
}

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        id.clear();
        for(int i = 0; i < n; i++)
            cin >> names[i], id[names[i]] = i, adj[i].clear(), vis[i] = -1;
        string x, y;
        char eq;
        double rel;
        for(int i = 0; i < n - 1; i++){
            cin >> x >> eq >> rel >> y;
            adj[id[x]].push_back({id[y], rel});
            adj[id[y]].push_back({id[x], 1.0 / rel});
        }
        dfs(0, 1);
        for(int i = 0; i < n; i++)
            units[i] = {vis[i], i};
        sort(units, units + n);
        double mul = 1 / units[0].first;
        for(int i = 0; i < n-1; i++)
            cout << int(units[i].first * mul + 1e-9) << names[units[i].second] << " = ";
        cout << int(units[n-1].first * mul + 1e-9) << names[units[n-1].second] << endl;
    }
}