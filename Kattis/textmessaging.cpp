#include <bits/stdc++.h>
using namespace std;

// Text Messaging Outrage

#define num long long int

int n, p, k, l;
num a[1003];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p >> k >> l;
        for(int j = 0; j < l; j++)
            cin >> a[j];
        sort(a, a + l, greater<num>());
        num ans = 0;
        for(int j = 0; j < l; j++)
            ans += a[j] * (j / k + 1);
        cout << "Case #" << i << ": " << ans << endl;
    }
}