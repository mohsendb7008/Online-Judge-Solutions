#include <bits/stdc++.h>
using namespace std;

// Estimating the Area of a Circle

double r, m, c;

int main(){
    cout << fixed << setprecision(10);
    while(1){
        cin >> r >> m >> c;
        if(!(r + m + c))
            break;
        cout << M_PI * r * r << " " << 4 * r * r * c / m << endl;
    }
}