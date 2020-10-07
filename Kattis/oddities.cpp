#include <bits/stdc++.h>
using namespace std;

// Oddities

int n, x;

int main(){
    cin >> n;
    while(n--){
        cin >> x;
        cout << x << " is " << (x % 2 ? "odd" : "even") << endl; 
    }
}