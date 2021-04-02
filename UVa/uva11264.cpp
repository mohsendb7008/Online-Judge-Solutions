#include <bits/stdc++.h>
using namespace std;

// Coin Collector

int t, n;
long long int a[1003], s[1003], c[1003];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        a[n] = LLONG_MAX;
        // long long int ans = 1;
        // for(int i = 0; i < n; i++){
        //     s[i] = a[i], c[i] = 1;
        //     for(int j = 0; j < i; j++)
        //         if(s[j] < a[i] && s[j] + a[i] < a[i+1] && c[j] + 1 > c[i]){
        //             s[i] = s[j] + a[i];
        //             c[i] = c[j] + 1;
        //         }
        //     ans = max(ans, c[i]);
        // }
        int ans = 1;
        long long int sum = 1;
        for(int i = 1; i < n; i++)
            if(sum + a[i] < a[i+1])
                ans++, sum += a[i];
        cout << ans << endl;
    }
}