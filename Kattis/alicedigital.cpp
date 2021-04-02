#include <bits/stdc++.h>
using namespace std;

// Alice in the Digital World

int n, m;
int a[100003];
int dp[100003];
int dp2[100003];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        dp[0] = a[0] > m ? a[0] : 0;
        for(int i = 1; i < n; i++)
            dp[i] = a[i] > m ? max(a[i], a[i]+dp[i-1]) : 0;
        dp2[n-1] = a[n-1] > m ? a[n-1] : 0;
        for(int i = n-2; i >= 0; i--)
            dp2[i] = a[i] > m ? max(a[i], a[i]+dp2[i+1]) : 0;
        int ans = m;
        for(int i = 0; i < n; i++)
            if(a[i] == m)
                ans = max(ans, m + (i > 0 ? dp[i-1] : 0) + (i < n-1 ? dp2[i+1] : 0));
        cout << ans << endl;
    }
}