#include <bits/stdc++.h>
using namespace std;

#define num long long int

inline bool solve(num n){
    while(n > 1){
        if(n % 2)
            break;
        n /= 2;
    }
    return n != 1;
}

int main(){
    int t;
    num n;
    cin >> t;
    while(t--)
        cin >> n, cout << (solve(n) ? "YES" : "NO") << endl;
}