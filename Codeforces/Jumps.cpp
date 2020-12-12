#include <bits/stdc++.h>
using namespace std;

#define num long long int

int main(){
    int t;
    cin >> t;
    while(t--){
        num x, lo = 1, hi = 1000000;
        cin >> x;
        while(lo < hi){
            num mid = (lo + hi) / 2;
            num b = (mid * (mid + 1)) / 2;
            if(x > b || x == b - 1)
                lo = mid + 1;
            else
                hi = mid;
        }
        cout << lo << endl;
    }
}