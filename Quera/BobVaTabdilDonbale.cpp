#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 3;

#define num long long int

int n;
num k, b[maxn], c[maxn], ps[maxn], ans = LLONG_MAX;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> b[i], c[i] = b[i] - k * i;
    sort(c, c + n);
    partial_sum(c, c + n, ps);
    for(int i = 0; i < n; i++){
        num a0 = b[i] - k * i;
        int ptr = upper_bound(c, c + n, a0) - c;
        ans = min(ans, a0 * ptr - (ptr ? ps[ptr-1] : 0) + ps[n-1] - (ptr ? ps[ptr-1] : 0) - a0 * (n - ptr));
    }
    cout << ans << endl;
}