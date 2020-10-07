#include <bits/stdc++.h>
using namespace std;

// A Vicious Pikeman (Hard)

// Very beautiful problem with hashing.
// Also finding loop in recursive generator helps you optimize your solution. 

#define num long long int

const num MAXC = 1e6+3;
const num MOD = 1e9+7;

num N, T, A, B, C, t;

vector<num> sequence;
map<num, num> indices;
num cnt[MAXC];

int main(){
    cin >> N >> T >> A >> B >> C >> t;
    fill_n(cnt, C+1, 0);
    sequence.push_back(t), indices[t] = 0;
    num i = 1;
    for(; i < N; i++){
        t =  (A * t + B) % C + 1;
        if(indices.find(t) != indices.end())
            break;
        sequence.push_back(t), indices[t] = i;
    }
    for(num a : sequence)
        cnt[a]++;
    N -= i;
    if(N){
        i = indices[t];
        num r = sequence.size() - i;
        for(num j = i; j < sequence.size(); j++)
            cnt[sequence[j]] += N / r + ((N % r && j - i < N % r) ? 1 : 0);
    }
    num ans = 0, penalty = 0, ptr = 0;
    for(num p = 1; p <= C; p++){
        if(!cnt[p])
            continue;
        if(p > T)
            break;
        num r = min(cnt[p], T / p);
        T -= r * p, ans += r;
        num pe1 = (ptr%MOD * r) % MOD;
        num pe2 = (r % 2 ? r*((r+1)/2) : (r/2)*(r+1)) % MOD;
        pe2 = (pe2 * p) % MOD;
        penalty = (((penalty + pe1) % MOD) + pe2) % MOD;
        ptr += r * p;
    }
    cout << ans << " " << penalty << endl;
}