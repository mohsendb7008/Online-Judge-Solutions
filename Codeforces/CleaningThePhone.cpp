#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 2e5 + 3;

int n, l[maxn], oneptr, twoptr;
num m, w[maxn], ones[maxn], twos[maxn], oneps[maxn], twops[maxn];

inline int solve(){
    oneptr = twoptr = 0;
    for(int i = 0; i < n; i++){
        if(l[i] == 1)
            ones[oneptr++] = w[i];
        else
            twos[twoptr++] = w[i];
    }
    sort(ones, ones + oneptr, greater<num>());
    sort(twos, twos + twoptr, greater<num>());
    partial_sum(ones, ones + oneptr, oneps);
    partial_sum(twos, twos + twoptr, twops);
    int ans = INT_MAX;
    for(int i = 0; i < oneptr; i++){
        if(oneps[i] >= m){
            ans = min(ans, i + 1);
            continue;
        }
        num need = m - oneps[i];
        if(!twoptr || twops[twoptr-1] < need)
            continue;
        int j = lower_bound(twops, twops + twoptr, need) - twops;
        ans = min(ans, i + 2 * j + 3);
    }
    if(!twoptr || twops[twoptr-1] < m)
        return ans;
    int j = lower_bound(twops, twops + twoptr, m) - twops;
    ans = min(ans, 2 * j + 2);
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        num sum = 0;
        for(int i = 0; i < n; i++)
            cin >> w[i], sum += w[i];
        for(int i = 0; i < n; i++)
            cin >> l[i];
        cout << (sum >= m ? solve() : -1) << endl;
    }
}