#include <bits/stdc++.h>
using namespace std;

// Sum Kind of Problem

int main(){
    int t;
    cin >> t;
    while(t--){
        int k, n;
        cin >> k >> n;
        cout << k << ' ' << (n * (n + 1)) / 2 << ' ' << n * n << ' ' << n * (n + 1) << '\n';
    }
}