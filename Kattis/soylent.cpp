#include <bits/stdc++.h>
using namespace std;

// Soylent

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << n / 400 + ((n % 400) ? 1 : 0) << '\n';
    }
}