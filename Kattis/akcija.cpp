#include <bits/stdc++.h>
using namespace std;

// Akcija

#define num long long int

const int maxn = 1e5 + 3;

int n;
num a[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<num>());
    num ans = 0;
    for(int i = 0; i < n; i++)
        if(i % 3 != 2)
            ans += a[i];
    cout << ans << endl;
}