#include <bits/stdc++.h>
using namespace std;

int a[13]{10, 30, 50, 70, 90, 110, 130, 150, 170, 190};
int n, x, y;

int main(){
    for(int i = 0; i < 10; i++)
        a[i] = a[i] * a[i];
    int ans = 0;
    cin >> n;
    while(n--)
        cin >> x >> y, ans += 10 - (lower_bound(a, a + 10, x * x + y * y) - a);
    cout << ans << endl;
}