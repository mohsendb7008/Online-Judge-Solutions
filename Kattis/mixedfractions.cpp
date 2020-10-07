#include <bits/stdc++.h>
using namespace std;

// Mixed Fractions

#define num long long int

num a, b;

int main(){
    while(1){
        cin >> a >> b;
        if(!(a + b))
            break;
        cout << a / b << " " << a % b << " / " << b << endl;
    }
}