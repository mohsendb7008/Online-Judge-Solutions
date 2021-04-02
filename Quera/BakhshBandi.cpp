#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n;
num a[23], ms[(1 << 20) + 3];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int mask = 1; mask < (1 << n); mask++)
        for(int i = 0; i < n; i++)
            if(mask & (1 << i))
                ms[mask] += a[i];
    num ans = LLONG_MAX;
    for(int mask = 0; mask < (1 << n); mask++)
        ans = min(ans, abs(ms[mask] - ms[(1 << n) - 1 - mask]));
    cout << ans << endl;
}