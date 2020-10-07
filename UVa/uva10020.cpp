#include <bits/stdc++.h>
using namespace std;

// Minimal coverage

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    if(p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

vector<pair<int, int>> intervals;
vector<int> indices;
int min_coverage(int A, int B){ // 0 means impossible
    int n = intervals.size();
    indices.clear();
    sort(intervals.begin(), intervals.end(), cmp);
    int ptr = -1, ans = 0, coverage = A;
    while(ptr < n){
        if(coverage >= B)
            break;
        int nexty = -1, maxn = INT_MIN;
        for(int j = ptr + 1; j < n; j++)
            if(intervals[j].first <= coverage && intervals[j].second > maxn){
                nexty = j;
                maxn = intervals[j].second;
            }
        if(nexty == -1)
            return 0;
        ptr = nexty, ans++, coverage = intervals[nexty].second;
        indices.push_back(nexty);
    }
    if(coverage >= B)
        return ans;
    return 0;
}

int main(){
    int t, M, x, y;
    bool first = true;
    cin >> t;
    while(t--){
        if(!first)
            cout << endl;
        first = false;
        cin >> M;
        intervals.clear();
        while(1){
            cin >> x >> y;
            if(x == 0 && y == 0)
                break;
            if(y < 0 || x > M)
                continue;
            intervals.push_back({x, y});
        }
        int ans = min_coverage(0, M);
        cout << ans << endl;
        if(ans)
            for(int i : indices)
                cout << intervals[i].first << " " << intervals[i].second << endl;
    }
}