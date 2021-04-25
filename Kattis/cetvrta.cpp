#include <bits/stdc++.h>
using namespace std;

// Cetvrta

int x1, y11, x2, y2, x3, y3;

int main(){
    cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3;
    if(x1 == x2)
        cout << x3 << ' ';
    else if(x1 == x3)
        cout << x2 << ' ';
    else 
        cout << x1 << ' ';
    if(y11 == y2)
        cout << y3 << '\n';
    else if(y11 == y3)
        cout << y2 << '\n';
    else
        cout << y11 << '\n';
}