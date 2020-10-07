#include <bits/stdc++.h>
using namespace std;

// Pick up sticks

int n, m;
vector<int> adj[1000003];
int indeg[1000003];
queue<int> kahn;
vector<int> order;

int main(){
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, adj[x-1].push_back(y-1), indeg[y-1]++;
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            kahn.push(i);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        order.push_back(u);
        for(int v : adj[u]){
            indeg[v]--;
            if(!indeg[v])
                kahn.push(v);
        }
    }
    if(order.size() < n)
        cout << "IMPOSSIBLE" << endl;
    else for(int i : order)
        cout << i + 1 << endl;
}