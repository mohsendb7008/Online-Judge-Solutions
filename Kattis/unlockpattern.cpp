#include <bits/stdc++.h>
using namespace std;

// Unlock Pattern

double x[10], y[10], ans = 0;
int ind;

int main(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> ind, x[ind] = i, y[ind] = j;
    for(int i = 1; i < 9; i++)
        ans += hypot(x[i] - x[i+1], y[i] - y[i+1]);
    cout << fixed << setprecision(10) << ans << endl;
}