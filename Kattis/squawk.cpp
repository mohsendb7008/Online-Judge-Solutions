#include <bits/stdc++.h>
using namespace std;

// Squawk Virus

int n, m, s, t;
long long int sq[103], tmp[103];
vector<int> adj[103];

int main(){
    cin >> n >> m >> s >> t;
    int u, v;
    while(m--)
        cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    sq[s] = 1;
    while(t--){
        fill_n(tmp, n, 0);
        for(int i = 0; i < n; i++)
            for(int j : adj[i])
                tmp[j] += sq[i];
        copy_n(tmp, n, sq);
    }
    cout << accumulate(sq, sq + n, 0ll) << endl;
}