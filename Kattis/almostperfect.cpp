#include <bits/stdc++.h>
using namespace std;

// Almost Perfect

#define num long long int

num fast_pow(num a, num b){
    if(!b)
        return 1;
    if(b % 2)
        return a * fast_pow(a, b - 1);
    num m = fast_pow(a, b / 2);
    return m * m;
}

const int maxn = 1e5;
bitset<maxn + 1> pf;
vector<num> primes;

num n, x, sd;
map<num, num> factors;

int main(){
    pf.set();
    for(num p = 2; p <= maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q <= maxn; q += p)
                pf[q] = 0;
        }
    while(cin >> n){
        x = n, sd = 1, factors.clear();
        for(num p : primes){
            if(p * p > x)
                break;
            while(!(x % p))
                factors[p]++, x /= p;
        }
        if(x > 1)
            factors[x]++;
        for(auto p : factors)
            sd *= (fast_pow(p.first, p.second + 1) - 1) / (p.first - 1);
        sd -= n;
        cout << n;
        if(sd == n)
            cout << " perfect" << endl;
        else if(abs(sd - n) <= 2)
            cout << " almost perfect" << endl;
        else
            cout << " not perfect" << endl;
    }
}