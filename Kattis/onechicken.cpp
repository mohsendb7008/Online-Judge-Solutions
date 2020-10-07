#include <bits/stdc++.h>
using namespace std;

// One Chicken Per Person!

int n, m, d;

int main(){
    cin >> n >> m, d = abs(n - m);
    cout << "Dr. Chaz ";
    cout << (m > n ? "will have " : "needs ") << d << (m > n ? "" : " more");
    cout << " piece" << (d == 1 ? "" : "s") << " of chicken";
    cout << (m > n ? " left over!" : "!") << endl; 
}