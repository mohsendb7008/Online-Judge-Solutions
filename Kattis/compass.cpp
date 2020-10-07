#include <bits/stdc++.h>
using namespace std;

// Jumbled Compass

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    int d1 = (n2 - n1 + 360) % 360;
    int d2 = (n1 - n2 + 360) % 360;
    if(d1 <= d2)
        cout << d1 << endl;
    else
        cout << -d2 << endl;
}