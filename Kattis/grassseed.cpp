#include <bits/stdc++.h>
using namespace std;

// Grass Seed Inc.

double c, l, w, ans = 0;
int n;

int main(){
    cin >> c >> n;
    for(int i = 0; i < n; i++)
        cin >> l >> w, ans += l * w;
    cout << fixed << setprecision(8) << ans * c << endl;
}