#include <bits/stdc++.h>
using namespace std;
#define num long long int

// Cocoa Coalition
num n, m, a, b;

int main(){
    cin >> n >> m >> a;
    if(a % n == 0 || a % m == 0){
        cout << 1 << endl;
        return 0;
    }
    b = n * m - a;
    for(num i = 1; i <= n; i++)
        if((a % i == 0 && a / i >= 1 && a / i <= m) || 
           (b % i == 0 && b / i >= 1 && b / i <= m)){
                cout << 2 << endl;
                return 0;
        }
    cout << 3 << endl;
}