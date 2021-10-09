#include <bits/stdc++.h>
using namespace std;

// Booking a Room

int n, r, t[103];

int main() {
    cin >> n >> r;
    if (n == r) {
        cout << "too late" << endl;
        return 0;
    }
    int x;
    while(r--)
        cin >> x, t[x] = 1;
    for(int i = 1; i <= n; i++)
        if(!t[i]){
            cout << i << endl;
            break;
        }
}