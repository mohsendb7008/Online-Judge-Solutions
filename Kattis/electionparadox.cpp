#include <bits/stdc++.h>
using namespace std;

// Election Paradox

int n, a[1003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sort(a, a + n, greater<int>());
    }
    int ans = 0;
    for(int i = 0; i < n / 2; i++){
        ans += a[i];
    }
    for(int i = n / 2; i < n; i++){
        ans += a[i] / 2;
    }
    cout << ans << endl;
}