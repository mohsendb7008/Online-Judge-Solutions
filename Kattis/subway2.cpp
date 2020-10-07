#include <bits/stdc++.h>
using namespace std;

// Subway

inline double dist(pair<double, double> p1, pair<double, double> p2){
    double dx = p1.first - p2.first, dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

pair<int, int> src, dst;
set<pair<int, int>> points;
vector<pair<int, int>> line;
map<pair<int, int>, vector<pair<int, int>>> subway;
map<pair<int, int>, double> dis;
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> dij;

int main(){
    cin >> src.first >> src.second >> dst.first >> dst.second;
    points.insert(src), points.insert(dst);
    int x, y;
    while(cin >> x >> y){
        line.clear();
        line.push_back({x, y});
        while(1){
            cin >> x >> y;
            if(x == -1 && y == -1)
                break;
            line.push_back({x, y});
        }
        for(int i = 0; i < line.size(); i++){
            points.insert(line[i]);
            if(i > 0)
                subway[line[i]].push_back(line[i-1]);
            if(i < line.size() - 1)
                subway[line[i]].push_back(line[i+1]);
        }
    }
    for(pair<int, int> point : points)
        dis[point] = INT_MAX;
    dis[src] = 0;
    dij.push({0, src});
    while(!dij.empty()){
        double w = dij.top().first;
        pair<int, int> u = dij.top().second;
        dij.pop();
        if(dis[u] < w)
            continue;
        for(pair<int, int> v : points){
            double c = 3 * dist(u, v) / 500;
            if(dis[u] + c < dis[v])
                dis[v] = dis[u] + c, dij.push({dis[v], v});
        }
        for(pair<int, int> v : subway[u]){
            double c = 3 * dist(u, v) / 2000;
            if(dis[u] + c < dis[v])
                dis[v] = dis[u] + c, dij.push({dis[v], v});
        }
    }
    int ans = dis[dst];
    if(dis[dst] - ans <= ans + 1 - dis[dst])
        cout << ans << endl;
    else
        cout << ans + 1 << endl;
}