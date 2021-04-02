#include <bits/stdc++.h>
using namespace std;

// Dragon Ball II

#define num long long int
#define inf LLONG_MAX

int n, m, k;
vector<pair<int, num>> adj[1003];
set<int> drags[1003];
int mapping[1003];
set<int> test;
num dist[1003][(1<<7)+3];

int main(){
    srand(time(0));
    cin >> n >> m >> k;
    int x, y;
    num w;
    while(m--)
        cin >> x >> y >> w, adj[x-1].push_back({y-1, w}), adj[y-1].push_back({x-1, w});
    while(k--)
        cin >> x >> y, drags[x-1].insert(y-1);
    int tries = 1000;
    num ans = inf;
    while(tries--){
        test.clear();
        for(int i = 0; i < n; i++)
            mapping[i] = rand() % 7, test.insert(mapping[i]);
        if(test.size() < 7)
            continue;
        for(int i = 0; i < n; i++)
            for(int d = 0; d < (1 << 7); d++)
                dist[i][d] = inf;
        int mask = 0;
        for(int drag : drags[0])
            mask |= (1 << mapping[drag]);
        dist[0][mask] = 0;
        priority_queue<pair<num, pair<int, int>>, vector<pair<num, pair<int, int>>>, greater<pair<num, pair<int, int>>>> dij; 
        dij.push({0, {0, mask}});
        while(!dij.empty()){
            num w = dij.top().first;
            int u = dij.top().second.first;
            int mask = dij.top().second.second;
            dij.pop();
            if(dist[u][mask] < w)
                continue;
            if(mask == (1 << 7) - 1){
                ans = min(ans, w);
                break;
            }
            for(pair<int, num> vv : adj[u]){
                num e = vv.second;
                int v = vv.first;
                int mask2 = mask;
                for(int drag : drags[v])
                    mask2 |= (1 << mapping[drag]);
                if(w + e < dist[v][mask2])
                    dist[v][mask2] = w + e, dij.push({w + e, {v, mask2}});
            }
        }
    }
    cout << (ans == inf ? -1 : ans) << endl;
}