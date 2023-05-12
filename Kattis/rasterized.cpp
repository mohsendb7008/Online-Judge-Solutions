#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

// Rasterized Lines

long long int _sieve_size;
bitset<10000010> pFlags;
vector<long long int> PF;

void sieve(long long int upperbound){
    _sieve_size = upperbound + 1;
    pFlags.set();
    pFlags[0] = pFlags[1] = 0;
    for(long long int q = 4; q <= _sieve_size; q += 2){
        pFlags[q] = 0;
    }
    PF.push_back(2);
    for(long long int p = 3; p <= _sieve_size; p += 2){
        if(pFlags[p]){
            for(long long int q = p * p; q <= _sieve_size; q += p){
                if(pFlags[q]){
                    pFlags[q] = 0;
                }
            }
            PF.push_back(p);
        }
    }
}

vector<long long int> factors;

long long int primeFactors(long long int N) {
    long long int PF_idx = 0, primefactor = PF[PF_idx], res = 0;
    while (primefactor * primefactor <= N) {
        while (N % primefactor == 0){
            N /= primefactor;
            factors.push_back(primefactor);
            res += primefactor;
        }
        if(PF_idx + 1 == PF.size()){
            break;
        } 
        primefactor = PF[++PF_idx];
    }
    if (N != 1)
        factors.push_back(N), res += N;
    return res;
}

long long int EulerPhi(long long int N) {
    long long int PF_idx = 0, primefactor = PF[PF_idx], ans = N;
    while (primefactor * primefactor <= N) {
        if (N % primefactor == 0)
            ans -= ans / primefactor;
        while (N % primefactor == 0)
            N /= primefactor;
        if(PF_idx + 1 == PF.size()){
            break;
        } 
        primefactor = PF[++PF_idx];
    }
    if (N != 1)
        ans -= ans / N;
    return ans;
}

set<long long int> divisors;

int main(){
    sieve(10000000);
    int tc;
    cin >> tc;
    while(tc--){
        long long int N;
        cin >> N;
        if(N == 1){
            cout << 1 << endl;
            continue;
        }
        factors.clear();
        primeFactors(N);
        int b = factors.size();
        divisors.clear();
        for(int i = 0; i < (1 << b); i++){
            long long int divisor = 1;
            for(int j = 0; j < b; j++){
                if(i & (1 << j)){
                    divisor *= factors[j];
                }
            }
            divisors.insert(divisor);
        }
        long long int ans = 0;
        for(long long int divisor: divisors){
            ans += EulerPhi(divisor + 1);
        }
        cout << ans << endl;
    }
}