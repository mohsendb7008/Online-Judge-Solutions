#include <bits/stdc++.h>
using namespace std;

// License to Launch

int n, x;

int main(){
    cin >> n;
    int mn = INT_MAX, ans;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x < mn)
            mn = x, ans = i;
    }
    cout << ans << endl;
}