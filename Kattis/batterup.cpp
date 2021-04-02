#include <bits/stdc++.h>
using namespace std;

// Batter Up

int n, a, sum = 0, cnt = 0;

int main(){
    cin >> n;
    while(n--){
        cin >> a;
        if(a != -1)
            sum += a, cnt++;
    }
    cout << fixed << setprecision(10) << double(sum) / cnt << endl;
}