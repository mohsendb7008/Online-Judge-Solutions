#include <bits/stdc++.h>
using namespace std;

// Brexit

int n, m, h, s;
vector<int> adj[200003];
int cnt[200003];
int indeg[200003];
bool vis[200003];

int main(){
    cin >> n >> m >> h >> s, h--, s--;
    fill_n(cnt, n, 0);
    int a, b;
    while(m--)
        cin >> a >> b, a--, b--, adj[a].push_back(b), adj[b].push_back(a), cnt[a]++, cnt[b]++;
    copy_n(cnt, n, indeg), fill_n(vis, n, false);
    queue<int> kahn;
    kahn.push(s), vis[s] = true;
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        for(int v : adj[u])
            if(!vis[v]){
                indeg[v]--;
                if(indeg[v] <= cnt[v] / 2)
                    kahn.push(v), vis[v] = true;
            }
    }
    cout << (vis[h] ? "leave" : "stay") << endl;
}