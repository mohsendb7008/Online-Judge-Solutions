#include <bits/stdc++.h>
using namespace std;

// Relatives

#define num long long int

const int maxn = 1e5;
bitset<maxn + 1> pf;
vector<int> primes;

int n, ans;

int main(){
    pf.set();
    for(num p = 2; p <= maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q <= maxn; q += p)
                pf[q] = 0;
        }
    while(1){
        cin >> n;
        if(!n)
            break;
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        ans = n;
        for(int p : primes){
            if(p * p > n)
                break;
            if(!(n % p))
                ans -= ans / p;
            while(!(n % p))
                n /= p;
        }
        if(n > 1)
            ans -= ans / n;
        cout << ans << endl;
    }
}