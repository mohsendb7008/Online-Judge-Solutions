#include <bits/stdc++.h>
using namespace std;

// Anthony and Diablo

double a, n;

int main(){
    cin >> a >> n;
    double r = sqrt(a / M_PI);
    if(2 * M_PI * r < n + 1e-9)
        cout << "Diablo is happy!" << endl;
    else
        cout << "Need more materials!" << endl;
}