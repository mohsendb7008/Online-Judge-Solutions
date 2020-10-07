#include <bits/stdc++.h>
using namespace std;

// Tired Terry

int n, p, d, psum[86400 * 2 + 3];
string s;

int main(){
    cin >> n >> p >> d >> s;
    psum[0] = s[0] == 'Z';
    for(int i = 1; i < n + p - 1; i++)
        psum[i] = psum[i-1] + (s[i%n] == 'Z');
    int ans = 0;
    if(psum[p-1] < d)
        ans++;
    for(int i = p; i < n + p - 1; i++)
        if(psum[i] - psum[i-p] < d)
            ans++;
    cout << ans << endl;
}