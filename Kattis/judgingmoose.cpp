#include <bits/stdc++.h>
using namespace std;

// Judging Moose

int main(){
    int l, r;
    cin >> l >> r;
    if(!(l + r)){
        cout << "Not a moose" << endl;
        return 0;
    }
    cout << (l == r ? "Even " : "Odd ") << max(l, r) * 2 << endl;
}