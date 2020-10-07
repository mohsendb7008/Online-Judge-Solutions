#include <bits/stdc++.h>
using namespace std;

// Tractor

#define num long long int

vector<num> po2;
num A, B, M, N;

int main(){
    for(int i = 0; i < 30; i++)
        po2.push_back(1 << i);
    int n;
    cin >> n;
    while(n--){
        cin >> A >> B, M = max(A, B), N = min(A, B);
        num ans = 0;
        for(num cand : po2){
            num a = cand - 1;
            num lo = max(0ll, a - M), hi = min(N, a);
            if(hi >= lo)
                ans += hi - lo + 1;
        }
        cout << ans << endl;
    }
}