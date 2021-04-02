#include <bits/stdc++.h>
using namespace std;

// Genius

int k, t, p, q, x[103], w[103][4+3];
double dp[103][103];

inline double win(int i, int a, int b){
    return double(w[i][a]) / (w[i][a] + w[i][b]);
}

double cdp(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == t)
        return dp[i][j] = j >= k;
    double p;
    if(x[i] == 0)
        p = win(i, 0, 1) * (win(i, 0, 2) * win(i, 2, 3) + win(i, 0, 3) * win(i, 3, 2));
    else if(x[i] == 1)
        p = win(i, 1, 0) * (win(i, 1, 2) * win(i, 2, 3) + win(i, 1, 3) * win(i, 3, 2));
    else if(x[i] == 2)
        p = win(i, 2, 3) * (win(i, 2, 0) * win(i, 0, 1) + win(i, 2, 1) * win(i, 1, 0));
    else
        p = win(i, 3, 2) * (win(i, 3, 0) * win(i, 0, 1) + win(i, 3, 1) * win(i, 1, 0));
    return dp[i][j] = p * cdp(i+1, j+1) + (1 - p) * cdp(i+1, j);
}

int main(){
    cin >> k >> t >> p >> q >> x[0];
    for(int i = 1; i < t; i++)
        x[i] = (x[i-1] * p) % q;
    for(int i = 0; i < t; i++)
        x[i] %= 4;
    for(int i = 0; i < t; i++)
        for(int j = 0; j < 4; j++)
            cin >> w[i][j];
    for(int i = 0; i <= t; i++)
        for(int j = 0; j <= t; j++)
            dp[i][j] = -1;
    cout << fixed << setprecision(10) << cdp(0, 0) << endl;
}