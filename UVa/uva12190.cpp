#include <bits/stdc++.h>
using namespace std;

// Electric Bill

#define num long long int

num A, B;

inline num f(num x){
    if(x <= 100)
        return x * 2;
    if(x <= 10000)
        return 2 * 100 + (x - 100) * 3;
    if(x <= 1000000)
        return 2 * 100 + 3 * 9900 + (x - 10000) * 5;
    return 2 * 100 + 3 * 9900 + 5 * 990000 + (x - 1000000) * 7;
}

inline num af(num x){
    if(x <= 2 * 100)
        return x / 2;
    if(x <= 2 * 100 + 3 * 9900)
        return (x - 2 * 100) / 3 + 100;
    if(x <= 2 * 100 + 3 * 9900 + 5 * 990000)
        return (x - 2 * 100 - 3 * 9900) / 5 + 10000;
    return (x - 2 * 100 - 3 * 9900 - 5 * 990000) / 7 + 1000000;
}

int main(){
    while(cin >> A >> B){
        if(A + B == 0)
            break;
        num left = 0;
        num right = A;
        while(left <= right){
            num x = (left + right) / 2;
            num y = af(B + f(x));
            num fxy = f(x + y);
            if(fxy == A){
                cout << f(x) << endl;
                break;
            }
            else if(fxy < A)
                left = x+1;
            else right = x-1;
        }
    }
}