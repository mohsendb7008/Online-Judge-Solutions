#include <bits/stdc++.h>
using namespace std;

// Tracking Shares

vector<pair<int, int>> events[366]; // events[day] = {company, new_share}
int share[21]; // share[company] 

int main(){
    int c, k, n, d;
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> k;
        while(k--)
            cin >> n >> d, events[d].push_back({i, n});
    }
    int ans = 0;
    for(int i = 0; i <= 365; i++){
        if(events[i].empty())
            continue;
        for(auto event : events[i]){
            ans -= share[event.first];
            share[event.first] = event.second;
            ans += share[event.first];
        }
        cout << ans << " ";
    }
    cout << endl;
}