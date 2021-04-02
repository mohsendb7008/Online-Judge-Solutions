#include <bits/stdc++.h>
using namespace std;

// Bank Queue

int n, t;
pair<int, int> jobs[10003];

int main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> jobs[i].first >> jobs[i].second;
    sort(jobs, jobs+n, greater<pair<int, int>>());
    multiset<int> selected;
    int ans = 0;
    for(int i = 0; i < n; i++){
        selected.insert(jobs[i].second);
        int T = 0;
        bool ok = true;
        for(int s : selected){
            if(s < T){
                ok = false;
                break;
            }
            T++;
        }
        if(ok) ans += jobs[i].first;
        else selected.erase(selected.find(jobs[i].second));
    }
    cout << ans << endl;
}