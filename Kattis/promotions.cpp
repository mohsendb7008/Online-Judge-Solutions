#include <bits/stdc++.h>
using namespace std;

// Promotions

int a, b, n, m, indeg[5003], indegr[5003], indegt[5003];
vector<int> adj[5003], adjr[5003];
vector<int> path;

inline bool topo(int sk, int up){
    copy_n(indeg, n, indegt);
    path.clear();
    queue<int> kahn;
    for(int i = 0; i < n; i++)
        if(!indegt[i])
            kahn.push(i);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        if(u == sk)
            continue;
        path.push_back(u);
        if(path.size() >= up)
            return false;
        for(int v : adj[u]){
            indegt[v]--;
            if(!indegt[v])
                kahn.push(v);
        }
    }
    return true;
}

inline bool topor(int sk, int up){
    copy_n(indegr, n, indegt);
    path.clear();
    queue<int> kahn;
    for(int i = 0; i < n; i++)
        if(!indegt[i])
            kahn.push(i);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        if(u == sk)
            continue;
        path.push_back(u);
        if(path.size() >= up)
            return false;
        for(int v : adjr[u]){
            indegt[v]--;
            if(!indegt[v])
                kahn.push(v);
        }
    }
    return true;
}

int main(){
    cin >> a >> b >> n >> m;
    path.reserve(n);
    int x, y;
    while(m--)
        cin >> x >> y, adj[x].push_back(y), indeg[y]++, adjr[y].push_back(x), indegr[x]++;
    int ansa = 0, ansb = 0, ansc = 0;
    for(int i = 0; i < n; i++){
        if(topo(i, a))
            ansa++;
        if(topo(i, b))
            ansb++;
        if(topor(i, n - b))
            ansc++;
    }
    cout << ansa << endl;
    cout << ansb << endl;
    cout << ansc << endl;    
}