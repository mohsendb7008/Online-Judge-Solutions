#include <bits/stdc++.h>
using namespace std;

// Star Arrangements

int n;

int main(){
    cin >> n;
    cout << n << ":" << endl;
    for(int i = 2; i < n; i++){
        int c = 2 * i - 1;
        if(n % c == 0 || (n + i - 1) % c == 0)
            cout << i << "," << i-1 << endl;
        if(n % i == 0)
            cout << i << "," << i << endl;
    }
}