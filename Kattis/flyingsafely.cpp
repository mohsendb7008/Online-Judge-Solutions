#include <bits/stdc++.h>
using namespace std;

// Flying Safely

int main(){
    int t, n, m, x;
    cin >> t;
    while(t--){
        cin >> n >> m, m *= 2;
        while(m--)
            cin >> x;
        cout << n - 1 << endl;
    }
}