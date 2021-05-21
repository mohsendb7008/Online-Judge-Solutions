#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, a[5003];
vector<int> h;
num dp[5003][5003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    set<int> planks;
    planks.insert(0);
    for(int i = 0; i < n; i++)
        planks.insert(a[i]);
    for(int p : planks)
        h.push_back(p);
    for(int i = 0; i < n; i++)
        a[i] = lower_bound(h.begin(), h.end(), a[i]) - h.begin();
    for(int i = n; i >= 0; i--)
        for(int j = 0; j < h.size(); j++){
            if(i == n){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(1 + dp[i+1][(h[j] < h[a[i]]) ? j : a[i]], max(0, h[a[i]] - h[j]) + dp[i+1][a[i]]);
        }
    cout << dp[0][0] << endl;
}