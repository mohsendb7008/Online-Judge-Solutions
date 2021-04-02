#include <bits/stdc++.h>
using namespace std;

// Transportation Planning

#define inf LLONG_MAX

int n, m, x[103], y[103];
double floyd[103][103];
vector<pair<int, int>> edges;

inline double dist(int i, int j){
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
} 

int main(){
    while(1){
        scanf("%d", &n);
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                floyd[i][j] = i == j ? 0 : inf;
        scanf("%d", &m);
        int x, y;
        while(m--)
            scanf("%d %d", &x, &y), floyd[x][y] = floyd[y][x] = dist(x, y);
        edges.clear();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(floyd[i][j] == inf)
                    edges.push_back({i, j});
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(floyd[i][k] != inf && floyd[k][j] != inf)
                        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
        double ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                ans += floyd[i][j];
        if(edges.empty()){
            printf("no addition reduces %.10f\n", ans);
            continue;
        }
        double best = ans;
        int bi, bj;
        for(pair<int, int> e : edges){
            int u = e.first, v = e.second;
            double d = dist(u, v);
            double curr = 0;
            for(int i = 0; i < n; i++)
                for(int j = i + 1; j < n; j++)
                    curr += min(floyd[i][j], min(floyd[i][u] + d + floyd[v][j], floyd[i][v] + d + floyd[u][j]));
            if(curr < best)
                best = curr, bi = u, bj = v;
            else if(curr = best){
                if(u < bi)
                    bi = u, bj = v;
                else if(u == bi)
                    bj = min(bj, v);
            }
        }
        printf("adding %d %d reduces %.10f to %.10f\n", bi, bj, ans, best);
    }
}