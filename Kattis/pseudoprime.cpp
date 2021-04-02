#include <bits/stdc++.h>
using namespace std;

// Pseudoprime numbers

#define num long long int

num a, p;

num fast_pow(num a, num b){
    if(!b)
        return 1;
    if(b % 2)
        return ((a % p) * fast_pow(a, b-1)) % p;
    num m = fast_pow(a, b/2);
    return (m * m) % p;
}

const int maxn = 1e6;

bitset<maxn + 1> pf;
vector<num> primes;

inline void init(){
    pf.set();
    for(num p = 2; p <= maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q <= maxn; q += p)
                pf[q] = 0;
        }
}

inline bool prime(num c){
    if(c <= maxn)
        return pf[c];
    for(num p : primes){
        if(p * p > c)
            break;
        if(!(c % p))
            return 0;
    }
    return 1;
}

int main(){
    init();
    while(1){
        cin >> p >> a;
        if(!(a + p))
            break;
        if(prime(p))
            cout << "no" << endl;
        else if(fast_pow(a, p) == a)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}