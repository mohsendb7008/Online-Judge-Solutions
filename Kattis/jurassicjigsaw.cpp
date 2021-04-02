#include <bits/stdc++.h>
using namespace std;

// Jurassic Jigsaw

const int maxn = 1000;

int n, k;
string dna[maxn + 3];
vector<pair<int, int>> adj[maxn + 3];
bool taken[maxn + 3];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
vector<pair<int, int>> ans;

int dsim(int i, int j){
    int ans = 0;
    for(int z = 0; z < k; z++)
        if(dna[i][z] != dna[j][z])
            ans++;
    return ans;
}

void prim(int u){
    taken[u] = true;
    for(auto v : adj[u])
        if(!taken[v.first])
            pq.push({v.second, {u, v.first}});
}


int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> dna[i];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            adj[i].push_back({j, dsim(i, j)}), adj[j].push_back({i, dsim(i, j)});
    prim(0);
    int mst = 0;
    while(!pq.empty()){
        int w = pq.top().first, u = pq.top().second.first, v = pq.top().second.second;
        pq.pop();
        if(taken[v])
            continue;
        mst += w;
        ans.push_back({u, v});
        prim(v);
    }
    cout << mst << endl;
    for(auto e : ans)
        cout << e.first << " " << e.second << endl;
}