#include <bits/stdc++.h>
using namespace std;

// Road Work

const int inf = INT_MAX;

int t, n, n1 = 1, n2 = 1, t1[253], t2[253], r1[253], r2[253], dp[253][253][253][3];
char c;

int main(){
    cin >> t >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'E')
            cin >> t1[n1] >> r1[n1], r1[n1] += t1[n1], n1++;
        if(c == 'W')
            cin >> t2[n2] >> r2[n2], r2[n2] += t2[n2], n2++; 
    }
    for(int p1 = 0; p1 < n1; p1++)
        for(int p2 = 0; p2 < n2; p2++)
            for(int ir = 0; ir <= n; ir++)
                for(int d = 0; d < 2; d++){
                    if(!(p1 + p2)){
                        dp[p1][p2][ir][d] = -3;
                        continue;
                    }
                    int ans = inf, subp;
                    dp[p1][p2][ir][d] = inf;
                    if(!(p1 + d))
                        continue;
                    if(!p2 && d)
                        continue;
                    if(!d){
                        subp = dp[p1-1][p2][ir][d];
                        if(subp != inf && max(subp + 3, t1[p1]) <= r1[p1])
                            ans = min(ans, max(subp + 3, t1[p1]));
                        if(ir){
                            subp = dp[p1-1][p2][ir-1][d];
                            if(subp != inf && max(subp + 3, t1[p1]) > r1[p1])
                                ans = min(ans, max(subp + 3, t1[p1]));
                        }
                        subp = dp[p1-1][p2][ir][!d];
                        if(subp != inf && max(subp + t, t1[p1]) <= r1[p1])
                            ans = min(ans, max(subp + t, t1[p1]));
                        if(ir){
                            subp = dp[p1-1][p2][ir-1][!d];
                            if(subp != inf && max(subp + t, t1[p1]) > r1[p1])
                                ans = min(ans, max(subp + t, t1[p1]));
                        }
                    }
                    else{
                        subp = dp[p1][p2-1][ir][d];
                        if(subp != inf && max(subp + 3, t2[p2]) <= r2[p2])
                            ans = min(ans, max(subp + 3, t2[p2]));
                        if(ir){
                            subp = dp[p1][p2-1][ir-1][d];
                            if(subp != inf && max(subp + 3, t2[p2]) > r2[p2])
                                ans = min(ans, max(subp + 3, t2[p2]));
                        }
                        subp = dp[p1][p2-1][ir][!d];
                        if(subp != inf && max(subp + t, t2[p2]) <= r2[p2])
                            ans = min(ans, max(subp + t, t2[p2]));
                        if(ir){
                            subp = dp[p1][p2-1][ir-1][!d];
                            if(subp != inf && max(subp + t, t2[p2]) > r2[p2])
                                ans = min(ans, max(subp +t, t2[p2]));
                        }
                    }
                    dp[p1][p2][ir][d] = ans;
                }
    int ans = 0;
    while(dp[n1-1][n2-1][ans][0] == inf && dp[n1-1][n2-1][ans][1] == inf)
        ans++;
    cout << ans << endl;
}