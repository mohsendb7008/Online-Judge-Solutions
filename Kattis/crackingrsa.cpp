#include <bits/stdc++.h>
using namespace std;

// Cracking RSA

bitset<1121> primes;

void init(){
    primes.set();
    primes[0] = 0;
    primes[1] = 0;
    for(int p = 2; p <= 1120; p++)
        if(primes[p]){
            for(int q = p * p; q <= 1120; q += p)
                primes[q] = 0;
        }
}

#define num long long int

num n, e, p, q, phi;

int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> e;
        for(num i = 2; 1; i++)
            if(primes[i] && n % i == 0){
                p = i, q = n / i;
                break;
            }
        phi = (p - 1) * (q - 1);
        for(num d = 2; 1; d++)
            if((d * e) % phi == 1){
                cout << d << endl;
                break;
            }
    }
}