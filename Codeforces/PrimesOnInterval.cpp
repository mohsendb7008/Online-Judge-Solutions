#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e6 + 3;

int a, b, k, pf[maxn], psum[maxn];

bool judge(int l){
    for(int x = a; x + l - 1 <= b; x++)
        if(psum[x + l - 1] - psum[x - 1] < k)
            return false;
    return true;
}

int main(){
    cin >> a >> b >> k;
    fill_n(pf, maxn, 1);
    pf[0] = pf[1] = 0;
    for(num p = 2; p < maxn; p++)
        if(pf[p])
            for(num q = p * p; q < maxn; q += p)
                pf[q] = 0;
    partial_sum(pf, pf + maxn, psum);
    if(psum[b] - psum[a-1] < k){
        cout << -1 << endl;
        return 0;
    }
    int lo = 1, hi = b - a + 1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}