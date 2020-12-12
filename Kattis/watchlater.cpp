#include <bits/stdc++.h>
using namespace std;

// Watch Later

int n, k, cnt = 1;
map<char, int> typ;
vector<int> vid;
vector<int> ind[23];
int masks[403][403];
int dp[(1 << 20) + 3];

int main(){
    char c;
    cin >> n >> k >> c;
    typ[c] = 0, vid.push_back(0), n--;
    while(n--){
        cin >> c;
        if(typ.find(c) == typ.end())
            typ[c] = cnt++;
        if(typ[c] != vid.back())
            vid.push_back(typ[c]);
    }
    n = vid.size();
    for(int i = 0; i < n; i++)
        ind[vid[i]].push_back(i);
    for(int i = 0; i < n; i++){
        int mask = 0;
        for(int j = i; j < n; j++)
            mask = mask | (1 << vid[j]), masks[i][j] = mask;
    }
    for(int i = 0; i < k; i++)
        dp[1 << i] = 1;
    for(int mask = 1; mask < (1 << k); mask++){
        if(dp[mask])
            continue;
        dp[mask] = INT_MAX;
        for(int i = 0; i < k; i++)
            if(mask & (1 << i)){
                int ans = 1;
                for(int j = 0; j < ind[i].size() - 1; j++)
                    if(masks[ind[i][j]+1][ind[i][j+1]-1] & mask)
                        ans++;
                dp[mask] = min(dp[mask], ans + dp[mask - (1 << i)]);
            }
    }
    cout << dp[(1 << k) - 1] << endl;
}