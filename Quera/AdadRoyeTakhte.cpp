#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;
const int inf = -1;

int s, t, n, a[103], dis[maxn];
queue<int> bfs;

int main(){
    cin >> s >> t >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    fill_n(dis, maxn, inf);
    dis[s] = 0;
    bfs.push(s);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int i = 0; i < n; i++){
            int v = (u * a[i]) % maxn;
            if(dis[v] == inf)
                dis[v] = dis[u] + 1, bfs.push(v);
        }
    }
    cout << dis[t] << endl;
}