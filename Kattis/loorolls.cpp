#include <bits/stdc++.h>
using namespace std;

// Loo Rolls

#define num long long int

int main(){
    num l, n;
    cin >> l >> n;
    num k = 0, sum = 0, save_n = n;
    while(1){
        k++;
        if(!(l % n))
            break;
        sum += l % n;
        if(!(sum % save_n))
            break;
        n -= l % n;
    }
    cout << k << endl;
}