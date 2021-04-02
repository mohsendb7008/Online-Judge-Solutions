#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;

int n, h[303];
vector<int> mount;
num dp[303][303][303];

num cdp(int i, int j, int k){
    if(i > j)
        return 1;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    num ans = ((cdp(i+1, j, k) + cdp(i, j-1, k)) % mod - cdp(i+1, j-1, k) + mod) % mod;
    if(h[i] == h[j] && h[i] >= mount[k])
        ans = (ans + cdp(i+1, j-1, lower_bound(mount.begin(), mount.end(), h[i]) - mount.begin())) % mod;
    return dp[i][j][k] = ans;
}

int main(){
    set<int> tmp;
    tmp.insert(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> h[i], tmp.insert(h[i]);
    for(int i : tmp)
        mount.push_back(i);
    for(int i = 0; i < 303; i++)
        for(int j = 0; j < 303; j++)
            for(int k = 0; k < 303; k++)
                dp[i][j][k] = -1;
    cout << cdp(0, n-1, 0) - 1 << endl;
}