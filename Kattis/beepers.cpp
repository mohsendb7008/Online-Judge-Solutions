#include <bits/stdc++.h>
using namespace std;

// Collecting Beepers

int n;
pair<int, int> points[13];
int graph[13][13];
int tsp[13][(1<<13)+3];

int ctsp(int node, int mask){
    if(tsp[node][mask] != -1)
        return tsp[node][mask];
    if(1<<(node-1) == mask)
        return tsp[node][mask] = graph[0][node];
    int ans = INT_MAX;
    for(int j = 1; j < n; j++)
        if(j != node && (mask & (1<<(j-1))))
            ans = min(ans, ctsp(j, mask - (1<<(node-1)) ) + graph[j][node]);
    return tsp[node][mask] = ans;
}

int main(){
    int t, x, y;
    cin >> t;
    while(t--){
        cin >> x >> y;
        cin >> points[0].first >> points[0].second;
        cin >> n;
        n++;
        for(int i = 1; i < n; i++)
            cin >> points[i].first >> points[i].second;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++){
                int dis = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
                graph[i][j] = dis;
                graph[j][i] = dis;
            }
        for(int i = 0; i < 13; i++)
            for(int j = 0; j < ((1<<13)+3); j++)
                tsp[i][j] = -1;
        int ans = INT_MAX;
        for(int i = 1; i < n; i++)
            ans = min(ans, ctsp(i, ((1<<(n-1))-1)) + graph[i][0]);
        cout << ans << endl;
    }
}