#include <bits/stdc++.h>
using namespace std;

// Loot Chest

const int maxn = 1000000;

int dl, dw;
double G, L, dp[maxn + 2][101];

int main(){
    cin >> dl >> dw >> G >> L;
    G = G / 100;
    L = L / 100;
    for(int i = maxn; i >= 1; i--){
        for(int p = 0; p <= 100; p++){
            double P = double(p) / 100;
            dp[i][p] = L * dp[i + 1][min(p + dl, 100)] + (1 - L) * ((1 - P) * dp[i + 1][min(p + dw, 100)] + P * ((1 - G) * dp[i+1][0] + G * i));
        }
    }
    cout << fixed << setprecision(10) << dp[1][0] << endl;
}