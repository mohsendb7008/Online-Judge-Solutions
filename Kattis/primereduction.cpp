#include <bits/stdc++.h>
using namespace std;

// Prime Reduction

#define num long long int

const int maxn = 1e5;
bitset<maxn + 1> pf;
vector<int> primes;

int x, cnt, n, s;

int main(){
    pf.set();
    for(num p = 2; p <= maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q <= maxn; q += p)
                pf[q] = 0;
        }
    while(cin >> x){
        if(x == 4)
            break;
        cnt = 0;
        while(1){
            cnt++, n = x, s = 0;
            for(int p : primes){
                if(p * p > x)
                    break;
                while(!(x % p))
                    s += p, x /= p;
            }
            if(x > 1)
                s += x;
            if(s == n){
                cout << n << " " << cnt << endl;
                break; 
            }
            x = s;
        }
    }
}