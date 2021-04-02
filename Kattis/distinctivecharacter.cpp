#include <bits/stdc++.h>
using namespace std;

// Distinctive Character

const int inf = INT_MAX;

int n, k, dis[(1 << 20) + 3];
queue<int> bfs;

int main(){
    cin >> n >> k;
    fill_n(dis, 1 << k, inf);
    string x;
    int mask;
    while(n--){
        cin >> x;
        mask = bitset<21>(x).to_ulong();
        dis[mask] = 0;
        bfs.push(mask);
    }
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int i = 0; i < k; i++){
            int v = u;
            if(u & (1 << i))
                v -= 1 << i;
            else
                v += 1 << i;
            if(dis[v] == inf)
                dis[v] = dis[u] + 1, bfs.push(v);
        }
    }
    int best = -1, ans;
    for(int mask = 0; mask < (1 << k); mask++)
        if(dis[mask] > best)
            best = dis[mask], ans = mask;
    for(int i = k - 1; i >= 0; i--)
        cout << ((ans & (1 << i)) ? '1' : '0');
    cout << endl;    
}