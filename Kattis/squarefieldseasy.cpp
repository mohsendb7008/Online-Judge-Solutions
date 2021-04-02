#include <bits/stdc++.h>
using namespace std;

// Square Fields (Easy)

int t, n, k;
pair<int, int> p[10];
vector<int> box[10];

int ans;
void track(int i){
    if(i == n){
        int curr = INT_MIN;
        for(int j = 0; j < k; j++){
            int minx = INT_MAX, miny = INT_MAX;
            int maxx = INT_MIN, maxy = INT_MIN;
            for(int x : box[j]){
                minx = min(minx, p[x].first);
                miny = min(miny, p[x].second);
                maxx = max(maxx, p[x].first);
                maxy = max(maxy, p[x].second);
            }
            curr = max(curr, max(maxy - miny, maxx - minx)); 
        }
        ans = min(ans, curr);
        return;
    }
    for(int j = 0; j < k; j++){
        box[j].push_back(i);
        track(i+1);
        box[j].pop_back();
    }
}

int main(){
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> p[i].first >> p[i].second;
        for(int i = 0; i < k; i++)
            box[i].clear();
        ans = INT_MAX;
        track(0);
        cout << "Case #" << test << ": " << ans << endl;
    }
}