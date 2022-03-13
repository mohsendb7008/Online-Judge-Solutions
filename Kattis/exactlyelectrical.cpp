// Exactly Electrical

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, t;
    cin >> a >> b >> c >> d >> t;
    int dis = abs(a - c) + abs(b - d);
    if(t < dis || (t - dis) % 2){
        cout << 'N' << endl;
    }
    else{
        cout << 'Y' << endl;
    }
}