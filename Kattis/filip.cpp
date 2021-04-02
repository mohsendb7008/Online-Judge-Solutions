#include <bits/stdc++.h>
using namespace std;

// Filip

char a[4], b[4];
int x, y;

int main(){
    cin >> a >> b;
    x = a[2] * 100 + a[1] * 10 + a[0];
    y = b[2] * 100 + b[1] * 10 + b[0];
    cout << max(x, y) - 111 * '0' << endl;
}