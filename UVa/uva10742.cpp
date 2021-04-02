#include <bits/stdc++.h>
using namespace std;

// The New Rule in Euphomia

bitset<1000001> primeFlags;
vector<int> primes;

int main(){
    primeFlags.set();
    primeFlags[0] = 0;
    primeFlags[1] = 0;
    for(int p = 2; p <= 1000000; p++)
        if(primeFlags[p]){
            primes.push_back(p);
            for(long long int q = ((long long int)p) * p; q <= 1000000; q += p)
                primeFlags[q] = 0;
        }
    int test = 1;
    int n;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        if(n <= 2){
            cout << "Case " << test++ << ": 0" << endl;
            continue;
        }
        int ans = 0;
        int ptr = lower_bound(primes.begin(), primes.end(), n) - primes.begin() - 1;
        for(int i = ptr; i >= 0; i--)
            ans += upper_bound(primes.begin(), next(primes.begin(), i), n - primes[i]) - primes.begin();
        cout << "Case " << test++ << ": " << ans << endl;
    }
}