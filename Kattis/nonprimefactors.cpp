#include <bits/stdc++.h>
using namespace std;

// Non-Prime Factors

#define num long long int

const int maxn = 1e4;
bitset<maxn + 1> pf;
vector<int> primes;

int q, n;
num memo[2000003];

int main(){
    pf.set();
    for(int p = 2; p <= maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(int q = p * p; q <= maxn; q += p)
                pf[q] = 0;
        }
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        num x = n;
        if(!memo[x]){
            num divisors = 1, factors = 0;
            for(int p : primes){
                if(p * p > n)
                    break;
                if(!(n % p)){
                    factors++;
                    num cnt = 0;
                    while(!(n % p))
                        cnt++, n /= p;
                    divisors *= (1 + cnt);  
                }
            }
            if(n > 1)
                factors++, divisors *= 2;
            memo[x] = divisors - factors;
        }
        printf("%lld\n", memo[x]);
    }
}