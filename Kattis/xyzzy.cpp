#include <bits/stdc++.h>
using namespace std;

// XYZZY

#define inf INT_MIN

int n;
vector<pair<int, int>> adj[103];
long long int dis[103];

int main(){
    while(1){
        cin >> n;
        if(n == -1)
            break;
        for(int i = 0; i < n; i++){
            adj[i].clear();
            int w, s, x;
            cin >> w >> s;
            while(s--)
                cin >> x, adj[i].push_back({x-1, w});
        }
        fill_n(dis, n, inf);
        dis[0] = 100;
        for(int _ = 0; _ < n-1; _++)
            for(int i = 0; i < n-1; i++)
                if(dis[i] != inf)
                    for(pair<int, int> j : adj[i])
                        if(dis[i] + j.second > 0)
                            dis[j.first] = max(dis[j.first], dis[i] + j.second);
        for(int _ = 0; _ < n-1; _++)
            for(int i = 0; i < n-1; i++)
                if(dis[i] != inf)
                    for(pair<int, int> j : adj[i])
                        if(dis[i] + j.second > 0 && dis[i] + j.second > dis[j.first])
                            dis[j.first] = INT_MAX;
        cout << (dis[n-1] == inf ? "hopeless" : "winnable") << endl; 
    }
}