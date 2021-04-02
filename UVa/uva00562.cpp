#include <bits/stdc++.h>
using namespace std;

// Dividing coins

int n;
int coins[103];

map<pair<int, int>, bool> m;

bool dp(int i, int d){
    if(i == -1)
        return d == 0;
    pair<int, int> p = make_pair(i, d);
    if(m.find(p) != m.end())
        return m[p];
    return m[p] = dp(i-1, d + coins[i]) || dp(i-1, abs(d - coins[i]));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        m.clear();
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> coins[i];
        for(int ans = 0; 562; ans++)
            if(dp(n-1, ans)){
                cout << ans << endl;
                break;
            }
    }
}