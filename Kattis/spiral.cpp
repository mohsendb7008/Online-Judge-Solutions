#include <bits/stdc++.h>
using namespace std;

// Prime Spiral

const int inf = INT_MAX;

bitset<30000> primeFlags;

void cprimes(){
    primeFlags.set();
    for(int p = 2; p < 30000; p++)
        if(primeFlags[p])
            for(int q = p * p; q < 30000; q += p)
                primeFlags[q] = 0;
}

int adjR[4]{0, -1, 0, 1};
int adjC[4]{1, 0, -1, 0};

set<pair<int, int>> g;
map<int, pair<int, int>> r;
map<pair<int, int>, int> dist;

int bfs(int x1, int y1, int x2, int y2){
    if(x1 == x2 && y1 == y2)
        return 0;
    dist.clear(), dist[{x1, y1}] = 0;
    queue<pair<int, int>> q;
    q.push({x1, y1});
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int x = i + adjR[k], y = j + adjC[k];
            if(g.find({x, y}) != g.end() && dist.find({x, y}) == dist.end()){
                if(x == x2 && y == y2)
                    return dist[{i, j}] + 1;
                dist[{x, y}] = dist[{i, j}] + 1;
                q.push({x, y});
            }
        }
    }
    return inf;
}


int main(){
    cprimes();
    int i = 1, x = 0, y = 0, k = 0, inc = 1;
    g.insert({0, 0}), r[1] = {0, 0};
    while(i < 20000){
        for(int j = 0; j < inc; j++){
            i++, x += adjR[k], y += adjC[k];
            if(!primeFlags[i])
                g.insert({x, y}), r[i] = {x, y};
        } 
        k = (k + 1) % 4;
        for(int j = 0; j < inc; j++){
            i++, x += adjR[k], y += adjC[k];
            if(!primeFlags[i])
                g.insert({x, y}), r[i] = {x, y};
        }
        k = (k + 1) % 4;
        inc++;
    }
    int xx, yy;
    int t = 1;
    while(cin >> xx >> yy){
        int ans;
        auto r1 = r.find(xx), r2 = r.find(yy);
        if(r1 == r.end())
            ans = inf;
        else if(r2 == r.end())
            ans = inf;
        else 
            ans = bfs(r1->second.first, r1->second.second, r2->second.first, r2->second.second);
        cout << "Case " << t++ << ": ";
        if(ans == inf)
            cout << "impossible" << endl;
        else cout << ans << endl; 
    }
}