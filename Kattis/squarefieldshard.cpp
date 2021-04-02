#include <bits/stdc++.h>
using namespace std;

// Square Fields (Hard)

int t, n, k;
pair<int, int> p[18];
int sq[(1<<15)+3];
int dp[(1<<15)+3][18];

int main(){
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> p[i].first >> p[i].second;
        sq[0] = 0;
        for(int mask = 1; mask < (1 << n); mask++){
            int minx = INT_MAX, miny = INT_MAX;
            int maxx = INT_MIN, maxy = INT_MIN;
            for(int i = 0; i < n; i++)
                if(mask & (1<<i)){
                    minx = min(minx, p[i].first);
                    miny = min(miny, p[i].second);
                    maxx = max(maxx, p[i].first);
                    maxy = max(maxy, p[i].second);
                }
            sq[mask] = max(maxx - minx, maxy - miny);
        }
        for(int mask = 0; mask < (1 << n); mask++)
            for(int c = 0; c <= k; c++){
                if(mask){
                    dp[mask][c] = c > 0 ? sq[mask] : INT_MAX;
                    if(c > 0)
                        for(int prevy = (mask-1)&mask; prevy > 0; prevy = (prevy-1)&mask)
                                dp[mask][c] = min(dp[mask][c], max(sq[mask-prevy], dp[prevy][c-1]));
                }
                else dp[mask][c] = 0;
            }
        cout << "Case #" << test << ": " << dp[(1<<n)-1][k] << endl;
    }
}