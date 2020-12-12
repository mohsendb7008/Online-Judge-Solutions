#include <bits/stdc++.h>
using namespace std;

// Annoyed Coworkers

#define num long long int

const int maxn = 1e5 + 3;

int h, n;
num a[maxn], d[maxn];

bool judge(num ans){
    num ha = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > ans)
            return false;
        ha += (ans - a[i]) / d[i];
    }
    return ha >= h;
}

int main(){
    cin >> h >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> d[i];
    num lo = 0, hi = 1e17;
    while(lo < hi){
        num mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}