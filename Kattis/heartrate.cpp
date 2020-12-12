#include <bits/stdc++.h>
using namespace std;

// Heart Rate

int n;
double b, p;

int main(){
    cout << fixed << setprecision(4);
    cin >> n;
    while(n--){
        cin >> b >> p;
        cout << 60 * (b - 1) / p << " " << 60 * b / p << " " << 60 * (b + 1) / p << endl;
    }
}