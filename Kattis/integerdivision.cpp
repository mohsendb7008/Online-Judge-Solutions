#include<bits/stdc++.h>
using namespace std;

// Integer Division

int n, d, a;
map<int, long long int> divv;

int main(){
    cin >> n >> d;
    while(n--)
        cin >> a, divv[a/d]++;
    long long int ans = 0;
    for(auto p : divv)
        ans += (p.second * (p.second - 1)) / 2;
    cout << ans << endl;
}