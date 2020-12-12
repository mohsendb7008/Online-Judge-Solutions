#include <bits/stdc++.h>
using namespace std;

// Good Coalition

int t, n, s[153];
double p[153], dp[153][153];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> s[i] >> p[i], p[i] /= 100;
        for(int i = n; i >= 0; i--)
            for(int c = 0; c <= 150; c++){
                if(i == n)
                    dp[i][c] = c > 75;
                else
                    dp[i][c] = max(p[i] * dp[i+1][c+s[i]], dp[i+1][c]);
            }
        cout << fixed << setprecision(7) << 100 * dp[0][0] << endl;
    }
}