#include <bits/stdc++.h>
using namespace std;

// Gnoll Hypothesis

int n, k;
double s[2 * 503], ps[2 * 503], f[503];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    cout << fixed << setprecision(7);
    if(k == 1){
        for(int i = 0; i < n; i++)
            cout << 100.0 / n << " ";
        cout << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        s[i + n] = s[i];
    partial_sum(s, s + 2 * n, ps);
    f[0] = double(k) * (k-1) / (double(n) * (n - 1));
    for(int i = 1; i <= n - k; i++)
        f[i] = f[i-1] * (double(n - i - k + 1) / (n - i - 1));
    for(int i = n; i < 2 * n; i++){
        double ans = 0;
        for(int d = 0; d <= n - k; d++)
            ans += f[d] * (ps[i] - ps[i-d-1]);
        cout << ans << " ";
    } 
    cout << endl;
}