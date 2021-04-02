#include <bits/stdc++.h>
using namespace std;

// Button Bashing

const int inf = INT_MAX;

vector<int> adj[3603];
int dist[3603];
queue<int> bfs;

int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i <= 3600; i++)
            adj[i].clear(), dist[i] = inf;
        int n, g, x;
        cin >> n >> g;
        while(n--){
            cin >> x;
            for(int i = 0; i <= 3600; i++){
                if(i + x > 3600)
                    adj[i].push_back(3600);
                else if(i + x < 0)
                    adj[i].push_back(0);
                else adj[i].push_back(i + x);
            }
        }
        dist[0] = 0, bfs.push(0);
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();
            for(int v : adj[u])
                if(dist[v] == inf)
                    dist[v] = dist[u] + 1, bfs.push(v);
        }
        int ans = g;
        while(dist[ans] == inf)
            ans++;
        cout << dist[ans] << " " << ans - g << endl;
    }
}