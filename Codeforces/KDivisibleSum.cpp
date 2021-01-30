#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(!(n % k))
            cout << 1 << endl;
        else
            cout << max(2, k / n + ((k % n) ? 1 : 0)) << endl;
    }
}