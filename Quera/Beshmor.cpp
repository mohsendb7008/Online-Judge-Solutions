#include <bits/stdc++.h>
using namespace std;

#define num long long int

num arr[200003];
num sp[200003];

int main(){
    int T;
    cin >> T;
    while(T--){
        num ans = 0;
        int n;
        num k;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        partial_sum(arr, arr+n, sp);
        sp[n] = 0;
        sort(sp, sp+n+1);
        for(int i = 0; i < n+1; i++){
            ans += n + 1 - (upper_bound(sp, sp+n+1, sp[i]+k) - sp);
        }
        cout << ans << endl;
    }
}