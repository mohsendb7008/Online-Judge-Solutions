#include <bits/stdc++.h>
using namespace std;

// Reseto

#define num long long int

const int maxn = 1e5 + 3;
bitset<maxn> pf;

int n, k;

int main(){
    pf.set();
    cin >> n >> k;
    for(num p = 2; p <= n; p++)
        if(pf[p])
            for(num q = p; q <= n; q += p)
                if(pf[q]){
                    pf[q] = 0;
                    k--;
                    if(!k){
                        cout << q << endl;
                        return 0;
                    }
                }
}