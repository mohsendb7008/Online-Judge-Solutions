#include <bits/stdc++.h>
using namespace std;

// Moogle

int n, k;
double h[203];
double dp[203][203];

double cdp(int i, int c){
    if(dp[i][c] != -1)
        return dp[i][c];
    double ans = INT_MAX;
    if(c == 0){
        double inter = 0;
        for(int j = 1; j < i; j++)
            inter += abs(h[j] - h[0] - (h[i] - h[0]) * j / i);
        ans = inter;
    }
    else{
        for(int s = c; s < i; s++){
            double inter = 0;
            for(int j = s + 1; j < i; j++)
                inter += abs(h[j] - h[s] - (h[i] - h[s]) * (j - s) / (i - s));
            ans = min(ans, inter + cdp(s, c-1));
        }
    }
    return dp[i][c] = ans;
}

int main(){
    cout << fixed << setprecision(4);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> h[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < k; j++)
                dp[i][j] = -1;
        cout << cdp(n-1, k-2) / n << endl;
    }
}