#include <bits/stdc++.h>
using namespace std;

// Primal Representation

#define num long long int

const int maxn = 1e5;
bitset<maxn + 1> pf;
vector<int> primes;

int x;
map<int, int> factors;

int main(){
    pf.set();
    for(num p = 2; p <= maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q <= maxn; q += p)
                pf[q] = 0;
        }
    int x;
    while(cin >> x){
        factors.clear();
        bool neg = x < 0;
        x = abs(x);
        for(int p : primes){
            if(p * p > x)
                break;
            while(!(x % p))
                factors[p]++, x /= p;
        }
        if(x > 1)
            factors[x]++;
        if(neg)
            cout << "-1 ";
        for(auto p : factors){
            cout << p.first;
            if(p.second > 1)
                cout << "^" << p.second;
            cout << " ";
        }
        cout << endl;
    }
}