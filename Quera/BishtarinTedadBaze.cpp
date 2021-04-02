#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n;
pair<int, int> intervals[maxn];

int main(){
    cin >> n;
    if(!n){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        cin >> intervals[i].second >> intervals[i].first;
    sort(intervals, intervals + n);
    int ans = 1, cover = intervals[0].first;
    for(int i = 1; i < n; i++)
        if(intervals[i].second >= cover)
            ans++, cover = intervals[i].first;
    cout << ans << endl;
}