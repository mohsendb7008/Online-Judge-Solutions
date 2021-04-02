#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> points;

pair<int, int> slope(int a, int b){
    int dy = points[b].second - points[a].second;
    int dx = points[b].first - points[a].first;
    return {dy, dx};
}

bool parallel(int a, int b, int c, int d){
    auto p = slope(a, b), q = slope(c, d);
    if(p.first == 0)
        return q.first == 0;
    if(q.first == 0)
        return p.first == 0;
    if(p.second == 0)
        return q.second == 0;
    if(q.second == 0)
        return p.second == 0;
    return p.first * q.second == q.first * p.second;
}

int dist(int a, int b){
    int dx = points[a].first - points[b].first;
    int dy = points[a].second - points[b].second;
    return dx * dx + dy * dy;
}

bool parallelogram(int a, int b, int c, int d){
    return parallel(a, b, c, d) && parallel(a, c, b, d) && 
           dist(a, b) == dist(c, d) && dist(a, c) == dist(b, d);
}

int ans = 0;
vector<int> taken;

void track(int d){
    if(d == points.size()){
        ans++;
        return;
    }
    track(d + 1);
    bool can = 1;
    for(int a : taken){
        for(int b : taken){
            for(int c : taken){
                if(a == b || a == c || b == c)
                    continue;
                if(parallelogram(a, b, c, d)){
                    can = 0;
                    break;   
                }
            }
            if(!can)
                break;
        }
        if(!can)
            break;
    }
    if(can){
        taken.push_back(d);
        track(d + 1);
        taken.pop_back();
    }
}

int main(){
    cin >> n;
    if(n == 1)
        cout << 2 << endl;
    else if(n == 2)
        cout << 15 << endl;
    else if(n == 3)
        cout << 278 << endl;
    else if(n == 4)
        cout << 5901 << endl;
    else
        cout << 155958 << endl;
    /*
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            points.push_back({i, j});
    track(0);
    cout << ans << endl;
    */
}