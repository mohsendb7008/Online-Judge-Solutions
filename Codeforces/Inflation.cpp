#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n;
num k, p[103];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> p[i];
        num ans = 0, psum = p[0];
        for(int i = 1; i < n; i++){
            if(p[i] * 100 <= k * psum){
                psum += p[i];
                continue;
            }
            num x = p[i] * 100 - k * psum;
            x = x / k + ((x % k) ? 1 : 0);
            ans += x, psum += p[i] + x;
        }
        cout << ans << endl;
    }
}