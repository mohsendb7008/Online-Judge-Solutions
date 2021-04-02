#include <bits/stdc++.h>
using namespace std;

// Sibice

#define EPS 1e-9

int n;
double w, h, l, x;

int main(){
    cin >> n >> w >> h;
    l = hypot(w, h);
    while(n--)
        cin >> x, cout << ((x < l + EPS) ? "DA" : "NE") << endl;
}