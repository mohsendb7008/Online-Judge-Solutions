#include <bits/stdc++.h>
using namespace std;

// Opening Ceremony

int n;
int h[100003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> h[i];
    sort(h, h+n);
    int ans = n;
    for(int i = 0; i < n; i++)
        ans = min(ans, h[i] + n-i-1);
    cout << ans << endl;
}