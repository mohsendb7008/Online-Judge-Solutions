// Tram

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double avg = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        avg += y - x;
    }
    cout << fixed << setprecision(10) << avg / n << endl;
}