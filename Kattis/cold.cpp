#include <bits/stdc++.h>
using namespace std;

// Cold-puter Science

int main(){
    int n, x, ans = 0;
    cin >> n;
    while(n--)
        cin >> x, ans += (x < 0) ? 1 : 0;
    cout << ans << endl;
}