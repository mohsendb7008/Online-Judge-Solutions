#include <bits/stdc++.h>
using namespace std;

// Climbing Worm

int main(){
    int a, b, h;
    cin >> a >> b >> h;
    int ans = 0, ptr = 0;
    while(1){
        ptr += a;
        ans++;
        if(ptr >= h)
            break;
        ptr -= b;
    }
    cout << ans << endl;
}