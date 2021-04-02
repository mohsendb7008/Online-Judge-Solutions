#include <bits/stdc++.h>
using namespace std;

// Password Hacking

double p[503];

int main(){
    int n;
    cin >> n;
    string alaki;
    for(int i = 0; i < n; i++)
        cin >> alaki >> p[i];
    sort(p, p + n, greater<double>());
    double ans = 0;
    for(int i = 1; i <= n; i++)
        ans += p[i - 1] * i;
    cout << fixed << setprecision(5) << ans << endl;
}