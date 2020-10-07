#include <bits/stdc++.h>
using namespace std;

// Minimum Scalar Product

int t, n;
long long int v1[803];
long long int v2[803]; 
long long int ans;

int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> v1[i];
        for(int i = 0; i < n; i++)
            cin >> v2[i];
        sort(v1, v1+n);
        sort(v2, v2+n, greater<long long int>());
        ans = 0;
        for(int i = 0; i < n; i++)
            ans += v1[i] * v2[i];
        cout << "Case #" << i << ": " << ans << endl;
    }
}