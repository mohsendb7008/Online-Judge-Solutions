#include <bits/stdc++.h>
using namespace std;

#define num long long int

num n, t, a[200003], psum[200003];
multiset<num> s;

int main(){
    cin >> n >> t;
    for(num i = 0; i < n; i++)
        cin >> a[i];
    partial_sum(a, a + n, psum);
    num ans = 0;
    for(num i = 0; i < n; i++){
        if(psum[i] < t)
            ans++;
        ans += distance(s.upper_bound(psum[i] - t), s.end());
        s.insert(psum[i]);
    } 
    cout << ans << endl;
}