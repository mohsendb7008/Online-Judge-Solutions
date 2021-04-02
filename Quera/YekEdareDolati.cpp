#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, m, indeg[maxn], indegc[maxn], h[maxn];
vector<int> adj[maxn];
priority_queue<int> kahn;
set<int> taken;

int main(){
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, adj[x-1].push_back(y-1), indeg[y-1]++;
    copy_n(indeg, n, indegc);
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            kahn.push(i);
    int it = n;
    while(!kahn.empty()){
        int u = kahn.top();
        kahn.pop();
        int deg = distance(taken.begin(), taken.upper_bound(u));
        if(deg != indegc[u]){
            cout << "No answer" << endl;
            return 0;
        }
        h[u] = it--;
        taken.insert(u);
        for(int v : adj[u]){
            indeg[v]--;
            if(!indeg[v])
                kahn.push(v);
        }
    }
    for(int i = 0; i < n; i++)
        cout << h[i] << " ";
    cout << endl;
}