#include <bits/stdc++.h>
using namespace std;

// Air Conditioned Minions

int n;
pair<int, int> intervals[103];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> intervals[i].first >> intervals[i].second;
    sort(intervals, intervals+n, [](const pair<int, int>& p1, const pair<int, int>& p2){
        return p1.second < p2.second;
    });
    int coverage = -1, ans = 0;
    for(int i = 0; i < n; i++)
        if(intervals[i].first > coverage)
            coverage = intervals[i].second, ans++;
    cout << ans << endl;
}