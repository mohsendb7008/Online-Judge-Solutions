#include <bits/stdc++.h>
using namespace std;

// Retribution!

int n, m, p;
pair<int, int> j[1003], r[1003], s[1003];
bool tj[1003], tr[1003], ts[1003];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq, pq2;

int main(){
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++)
        cin >> j[i].first >> j[i].second;
    for(int i = 0; i < m; i++)
        cin >> r[i].first >> r[i].second;
    for(int i = 0; i < p; i++)
        cin >> s[i].first >> s[i].second;
    for(int i = 0; i < n; i++)
        for(int k = 0; k < m; k++)
            pq.push({hypot(j[i].first - r[k].first, j[i].second - r[k].second), {i, k}});
    double ans = 0;
    int cnt = 0;
    while(cnt < n){
        auto p = pq.top();
        pq.pop();
        double dis = p.first;
        int i = p.second.first, k = p.second.second;
        if(tj[i] || tr[k])
            continue;
        ans += dis;
        cnt++;
        tj[i] = tr[k] = 1;
    }
    for(int i = 0; i < n; i++)
        for(int k = 0; k < p; k++)
            pq2.push({hypot(j[i].first - s[k].first, j[i].second - s[k].second), {i, k}});
    fill_n(tj, n, 0);
    cnt = 0;
    while(cnt < n){
        auto p = pq2.top();
        pq2.pop();
        double dis = p.first;
        int i = p.second.first, k = p.second.second;
        if(tj[i] || ts[k])
            continue;
        ans += dis;
        cnt++;
        tj[i] = ts[k] = 1;
    }
    cout << fixed << setprecision(7) << ans << endl;
}