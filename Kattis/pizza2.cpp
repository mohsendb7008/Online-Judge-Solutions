#include <bits/stdc++.h>
using namespace std;

// Pizza Crust

double r, c;

int main(){
    cin >> r >> c, cout << fixed << setprecision(10) << 100 * (r-c) * (r-c) / (r * r) << endl;
}