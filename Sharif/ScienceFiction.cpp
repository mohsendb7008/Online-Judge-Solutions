#include <bits/stdc++.h>
using namespace std;

set<int> powers_of_two{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

const int maxn = 1 << 10;

int n, a[maxn], parent[maxn];
vector<int> adj[maxn];
pair<int, int> sorted[maxn];
queue<int> bfs;
vector<int> path;
vector<pair<int, int>> swaps;

int main(){
    cin >> n, n = 1 << n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(powers_of_two.find(i ^ j) != powers_of_two.end())
                adj[i].push_back(j), adj[j].push_back(i);
    for(int destination = 0; destination < n; destination++){
        for(int i = 0; i < n; i++)
            sorted[i] = {a[i], i};
        sort(sorted, sorted + n);
        int source = sorted[destination].second;
        if(source == destination)
            continue;
        fill_n(parent, n, -1);
        path.clear();
        parent[source] = -2;
        bfs.push(source);
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();
            for(int v : adj[u])
                if(v >= destination && parent[v] == -1)
                    parent[v] = u, bfs.push(v);
        }
        int it = destination;
        while(it != -2)
            path.push_back(it), it = parent[it];
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size() - 1; i++)
            swaps.push_back({path[i], path[i + 1]}), swap(a[path[i]], a[path[i + 1]]);
    }
    cout << swaps.size() << endl;
    for(auto it : swaps)
        cout << it.first << " " << it.second << endl;
}