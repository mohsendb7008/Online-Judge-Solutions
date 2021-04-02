#include <bits/stdc++.h>
using namespace std;

// Bus Planning

int n, k, c, cnt, it;
string names[20], x, y;
map<string, int> indices;
bool bad[20][20], ok[1<<20];
int dp[1<<20], trace[1<<20];

int main(){
    cin >> n >> k >> c;
    for(int i = 0; i < n; i++)
        cin >> names[i], indices[names[i]] = i;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            bad[i][j] = false;
    while(k--)
        cin >> x >> y, bad[indices[x]][indices[y]] = true, bad[indices[y]][indices[x]] = true;
    for(int mask = 0; mask < (1<<n); mask++){
        ok[mask] = true, cnt = 0;
        for(int i = 0; i < n; i++)
            if(mask & (1<<i))
                cnt++;
        if(cnt > c){
            ok[mask] = false;
            continue;
        }
        for(int i = 0; i < n; i++){
            if(mask & (1<<i))
                for(int j = 0; j < n; j++)
                    if(j != i && (mask & (1<<j)) && bad[i][j]){
                        ok[mask] = false;
                        break;
                    }
            if(!ok[mask])
                break;
        }
    }
    dp[0] = 0;
    for(int mask = 1; mask < (1<<n); mask++){
        dp[mask] = INT_MAX;
        for(int prevy = mask; prevy > 0; prevy = (prevy-1)&mask)
            if(ok[prevy] && dp[mask-prevy] + 1 < dp[mask]){
                dp[mask] = dp[mask-prevy] + 1;
                trace[mask] = prevy;
            }
    }
    it = (1<<n)-1;
    cout << dp[it] << endl;
    while(it){
        int bus = trace[it];
        for(int i = 0; i < n; i++)
            if(bus & (1<<i))
                cout << names[i] << " ";
        cout << endl;
        it -= bus;
    }
}