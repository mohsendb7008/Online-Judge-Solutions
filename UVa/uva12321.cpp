#include <bits/stdc++.h>
using namespace std;

// Gas Stations

int n;
pair<int, int> intervals[10003];
vector<int> indices;

int min_coverage(int A, int B){ // -1 means impossible
    sort(intervals, intervals+n);
    indices.clear();
    int coverage = A, i = -1, cnt = 0;
    while(i < n){
        int cand = -1, maxl = INT_MIN;
        for(int j = i + 1; j < n; j++)
            if(intervals[j].first <= coverage && intervals[j].second >= maxl)
                cand = j, maxl = intervals[j].second;
        if(cand == -1)
            break;
        indices.push_back(cand);
        coverage = maxl, i = cand, cnt++;
        if(coverage >= B)
            break;
    }
    return coverage >= B ? cnt : -1;
}

int main(){
    int L, x, r;
    while(cin >> L >> n){
        if(!(L + n))
            break;
        for(int i = 0; i < n; i++){
            cin >> x >> r;
            intervals[i] = {x-r, x+r};
        }
        int ans = min_coverage(0, L);
        cout << (ans+1 ? n - ans : -1) << endl;
    }
}