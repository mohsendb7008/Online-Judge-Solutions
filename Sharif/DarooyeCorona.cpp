#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main(){
    cin >> a >> b >> c >> d;
    if(a - b > c - d)
        cout << "Shekarestan" << endl;
    else if(a - b < c - d)
        cout << "Namakestan" << endl;
    else
        cout << "Equal" << endl;
}