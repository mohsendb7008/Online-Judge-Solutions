#include<bits/stdc++.h>
using namespace std;

// Eating Out

int m, a, b, c;

int main(){
    cin >> m >> a >> b >> c;
    if(a + b + c > 2 * m)
        cout << "impossible" << endl;
    else cout << "possible" << endl;
}