// Warehouse

#include <bits/stdc++.h>
using namespace std;

map<string, int> cnt;
vector<pair<int, string>> ans;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cnt.clear();
        ans.clear();
        int n;
        cin >> n;
        while(n--){
            string x;
            int y;
            cin >> x >> y;
            cnt[x] += y;
        }
        for(auto it : cnt){
            ans.push_back({-it.second, it.first});
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto it : ans){
            cout << it.second << " " << -it.first << endl;
        }
    }
}