// Interval Scheduling

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n;
pair<int, int> a[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    int ans = 0;
    int cover = -1;
    for(int i = 0; i < n; i++){
        int l = a[i].second;
        int r = a[i].first;
        if(l < cover)
            continue;
        ans++;
        cover = r;
    }
    cout << ans << endl;
}