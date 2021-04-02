#include <bits/stdc++.h>
using namespace std;

// A List Game

#define num long long int

const int maxn = 1e5 + 3;

bitset<maxn> pf;
vector<int> primes;

int x;

int main(){
    pf.set();
    for(num p = 2; p < maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q < maxn; q += p)
                pf[q] = 0;
        }
    cin >> x;
    int ans = 0;
    for(int factor : primes){
        while(!(x % factor))
            ans++, x /= factor;
        if(x == 1)
            break;
    }
    if(x > 1)
        ans++;
    cout << ans << endl;
}