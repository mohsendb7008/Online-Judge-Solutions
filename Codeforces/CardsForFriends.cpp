#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int w, h, n;
        cin >> w >> h >> n;
        int ans = 1;
        while(!(w % 2))
            ans *= 2, w /= 2;
        while(!(h % 2))
            ans *= 2, h /= 2;
        cout << (ans >= n ? "YES" : "NO") << endl;
    }
}
