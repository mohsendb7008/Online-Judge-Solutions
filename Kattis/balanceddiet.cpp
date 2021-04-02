#include <bits/stdc++.h>
using namespace std;

// Balanced Diet

const int maxn = 20 * 600;

int n, a[23];
bool dp[maxn + 1];
bool tmp[maxn + 1];

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        int sum = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i], sum += a[i];
        fill_n(dp, maxn, false);
        dp[0] = true;
        for(int i = 0; i < n; i++){
            fill_n(tmp, maxn, false);
            for(int d = 0; d <= maxn; d++)
                if(dp[d]){
                    tmp[d + a[i]] = true;
                    tmp[abs(d - a[i])] = true;
                }
            copy_n(tmp, maxn, dp);
        }
        int d;
        for(d = 0; d <= maxn; d++)
            if(dp[d])
                break;
        int lo = (sum - d) / 2, hi = lo + d;
        cout << hi << " " << lo << endl;
    } 
}