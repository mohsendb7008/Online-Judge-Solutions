#include <bits/stdc++.h>
using namespace std;

// Falling Apart

int n, a[20], ans[3];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    for(int i = 0; i < n; i++)
        ans[i % 2] += a[i];
    cout << ans[0] << " " << ans[1] << endl;
}