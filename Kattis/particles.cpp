#include <bits/stdc++.h>
using namespace std;

// Particle Swapping

int n, x[503], y[503];
vector<int> adj[503];
struct edge{
    pair<int, int> u, v;
    int d;
    edge(pair<int, int> u, pair<int, int> v, int d){
        this->u = u;
        this->v = v;
        this->d = d;
    }
    bool operator<(const edge& o) const{
        return this->d > o.d;
    }
};
vector<edge> edges;
set<pair<int, int>> cc[500*500+3];
map<pair<int, int>, int> id;
int ans[503][503];

inline int dis(int i, int j){
    int dx = x[i] - x[j], dy = y[i] - y[j];
    return dx * dx + dy * dy;
}

int main(){
    cout << fixed << setprecision(10);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int m, u, v;
    cin >> m;
    while(m--)
        cin >> u >> v, u--, v--, adj[u].push_back(v);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j){
                for(int k : adj[i])
                    if(k != j)
                        edges.push_back(edge({i, j}, {k, j}, min(dis(i, j), dis(k, j))));
                for(int k : adj[j])
                    if(k != i)
                        edges.push_back({edge({i, j}, {i, k}, min(dis(i, j), dis(i, k)))});
            }
    sort(edges.begin(), edges.end());
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
                cc[cnt].insert({i, j}), id[{i, j}] = cnt++, ans[i][j] = -1;
    for(edge e : edges)
        if(id[e.u] != id[e.v]){
            int i = id[e.u], j = id[e.v];
            if(cc[i].size() > cc[j].size())
                swap(i, j);
            for(pair<int, int> u : cc[i]){
                if(ans[u.first][u.second] == -1 && cc[j].find({u.second, u.first}) != cc[j].end())
                    ans[u.first][u.second] = e.d, ans[u.second][u.first] = e.d;
                id[u] = j;
                cc[j].insert(u);
            }
        }
    cin >> m;
    while(m--){
        cin >> u >> v, u--, v--;
        double dans = ans[u][v];
        cout << sqrt(dans) << endl;
    }
}