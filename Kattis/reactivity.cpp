#include <bits/stdc++.h>
using namespace std;

// Reactivity Series

int n;
int indeg[1003];
vector<int> adj[1003];

int main(){
    int m, A, B;
    cin >> n >> m;
    fill_n(indeg, n, 0);
    while(m--){
        cin >> A >> B;
        adj[A].push_back(B);
        indeg[B]++;
    }
    queue<int> candidate;
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            candidate.push(i);
    vector<int> path;
    while(!candidate.empty()){
        if(candidate.size() > 1){
            cout << "back to the lab" << endl;
            return 0;
        }
        int u = candidate.front();
        candidate.pop();
        path.push_back(u);
        for(int v : adj[u]){
            indeg[v]--;
            if(!indeg[v])
                candidate.push(v);
        }
    }
    for(int u : path)
        cout << u << " ";
    cout << endl;
}