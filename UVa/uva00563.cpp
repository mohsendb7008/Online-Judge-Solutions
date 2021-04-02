#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Crimewave

const int maxn = 5103;
const int inf = INT_MAX;

// s: source, t: sink, c: capacity
int n, m, s, t, c[maxn][maxn], flow[maxn][maxn], par[maxn];
vector<int> adj[maxn];

int augment(){
    fill_n(par, n, -1);
    par[s] = -2;
    queue<pair<int, int>> bfs;
    bfs.push({s, inf});
    while(!bfs.empty()){
        int u = bfs.front().first, f = bfs.front().second;
        bfs.pop();
        if(u == t)
            return f;
        for(int v : adj[u])
            if(par[v] == -1 && c[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push({v, min(f, c[u][v] - flow[u][v])});
    }
    return 0;
}

int max_flow(){
    int ans = 0;
    while(1){
        int f = augment();
        if(!f)
            break;
        ans += f;
        int it = t;
        while(it != s){
            flow[par[it]][it] += f;
            flow[it][par[it]] -= f;
            it = par[it];
        }
    }
    return ans;
}
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};
int ss, a, b, x, y;
bool inrange(int i, int j){
    return i >= 0 && i < ss && j >= 0 && j < a; 
}
bool onborder(int i, int j){
    return i == 0 || i == ss-1 || j == 0 || j == a-1;
}
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        cin >> ss >> a >> b;
        n = 2 * ss * a + 2;
        s = 0;
        t = 2 * ss * a + 1;
        for(int i = 0; i < n; i++){
            adj[i].clear();
            for(int j = 0; j < n; j++){
                c[i][j] = flow[i][j] = 0;
            }
        }
        for(int i = 0; i < b; i++){
            cin >> x >> y; x--; y--;
            int vert = y * ss + x + 1, vert2 = vert+ss*a;
            adj[s].push_back(vert);
            c[s][vert] = 1;
        }
        for(int i = 0; i < ss; i++){
            for(int j = 0; j < a; j++){
                int vert = j * ss + i + 1, vert2 = vert+ss*a;
                adj[vert].push_back(vert2);
                c[vert][vert2] = 1;
                if(onborder(i, j)){
                    adj[vert2].push_back(t);
                    c[vert2][t] = 1;
                }
                for(int k = 0; k < 4; k++){
                    int nextx = i + dirx[k], nexty = j + diry[k];
                    if(inrange(nextx, nexty)){
                        int nextvert = nexty * ss + nextx + 1;
                        adj[vert2].push_back(nextvert);
                        c[vert2][nextvert] = 1;
                    }
                }
            }
        }
        if(max_flow() < b){
            cout << "not possible" << endl;
        }
        else{
            cout << "possible" << endl;
        }
    }
    return 0;
}