#include <bits/stdc++.h>
using namespace std;

// Boxed Letters

const int maxn = 72e3 + 3;

int n, m = 0, from[maxn], to[maxn], mask[maxn], dis[12][1<<12], par[12][1<<12], parm[12][1<<12];
string words[maxn], valids[maxn];
map<char, int> side, box;
vector<int> adj[12], ans;

int bfs(int src, int& dst, int& dst_mask){
    for(int i = 0; i < 12; i++)
        for(int sub = 0; sub < (1<<12); sub++)
            dis[i][sub] = -1;
    dis[src][0] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    while(!q.empty()){
        int u = q.front().first, sub = q.front().second;
        q.pop();
        if(sub == (1<<12) - 1){
            dst = u, dst_mask = sub;
            return dis[u][sub];
        }
        for(int e : adj[u]){
            int v = to[e], nsub = sub | mask[e];
            if(dis[v][nsub] == -1)
                dis[v][nsub] = dis[u][sub] + 1, par[v][nsub] = e, parm[v][nsub] = sub, q.push({v, nsub});
        }
    }
    return INT_MAX;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> words[i];
    char c;
    for(int i = 0; i < 3; i++)
        cin >> c, side[c] = 2, box[c] = i;
    for(int i = 0; i < 6; i++)
        cin >> c, side[c] = i % 2, box[c] = 3 + i;
    for(int i = 0; i < 3; i++)
        cin >> c, side[c] = 3, box[c] = 9 + i;
    for(int i = 0; i < n; i++){
        int ok = 1, curm = 0;
        for(int j = 0; j < words[i].size(); j++){
            if(side.find(words[i][j]) == side.end()){
                ok = 0;
                break;
            }
            if(j && side[words[i][j-1]] == side[words[i][j]]){
                ok = 0;
                break;
            }
            curm = curm | (1 << box[words[i][j]]);
        }
        if(ok)
            valids[m] = words[i], from[m] = box[words[i].front()], to[m] = box[words[i].back()], mask[m] = curm, adj[from[m]].push_back(m), m++;
    }
    int best = INT_MAX, best_src, it, it_mask;
    for(int i = 0; i < 12; i++){
        int cur = bfs(i, it, it_mask);
        if(cur < best)
            best = cur, best_src = i;
    }
    bfs(best_src, it, it_mask);
    while(it != best_src || it_mask){
        int e = par[it][it_mask], emask = parm[it][it_mask];
        ans.push_back(e);
        it = from[e], it_mask = emask;
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans)
        cout << valids[i] << endl;
}