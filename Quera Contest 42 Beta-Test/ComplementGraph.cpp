#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> edges;

int main(){
    int m;
    cin >> m >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        edges.insert({min(u, v), max(u, v)});
    }
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        cout << ((edges.find({min(u, v), max(u, v)}) != edges.end()) ? "NO" : "YES") << endl;
    }
}