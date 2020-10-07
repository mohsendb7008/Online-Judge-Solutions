#include <bits/stdc++.h>
using namespace std;

// Number Fun

int n, a, b, c;

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        if(a + b == c || a * b == c || a - b == c || b - a == c || (a % b == 0 && a / b == c) || (b % a == 0 && b / a == c))
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }
}