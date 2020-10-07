#include <bits/stdc++.h>
using namespace std;

// Arachnophobia

int N, M, K, T, s, t;
vector<pair<int, int>> adj[100003];
int sp[100003];
int dis[100003];

int main(){
    cin >> N >> M >> T;
    int x, y, d;
    for(int i = 0; i < M; i++){
        cin >> x >> y >> d;
        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
    }
    cin >> s >> t >> K;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill_n(sp, N, INT_MAX);
    for(int i = 0; i < K; i++)
        cin >> x, sp[x] = 0, pq.push({0, x});
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int d = p.first, u = p.second;
        if(sp[u] < d)
            continue;
        for(pair<int, int> p : adj[u]){
            int v = p.first, w = p.second;
            if(d + w < sp[v]){
                sp[v] = d + w;
                pq.push({d + w, v});
            }
        }
    }
    int start = 0, end = 2000000000;
    while(start < end){
        int mid = (start + end);
        mid = mid / 2 + (mid % 2 ? 1 : 0);
        fill_n(dis, N, INT_MAX);
        if(sp[s] >= mid){
            dis[s] = 0;
            pq.push({0, s});
        }
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int d = p.first, u = p.second;
            if(dis[u] < d)
                continue;
            for(pair<int, int> p : adj[u]){
                int v = p.first, w = p.second;
                if(sp[v] < mid)
                    continue;
                if(d + w < dis[v]){
                    dis[v] = d + w;
                    pq.push({d + w, v});
                }
            }
        }
        if(dis[t] <= T)
            start = mid;
        else end = mid - 1;
    }
    cout << start << endl;
}