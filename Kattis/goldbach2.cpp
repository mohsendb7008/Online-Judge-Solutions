#include <bits/stdc++.h>
using namespace std;

// Golbach's Conjecture

bitset<32001> primeFlags;
vector<int> primes;

vector<pair<int, int>> representations;

int main(){
    primeFlags.set();
    primeFlags[0] = 0;
    primeFlags[1] = 0;
    for(int p = 2; p <= 32000; p++){
        if(primeFlags[p]){
            primes.push_back(p);
            for(int q = p * p; q <= 32000; q += p)
                primeFlags[q] = 0;
        }
    }
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        representations.clear();
        for(int prime: primes){
            if(prime > x / 2)
                break;
            int other = x - prime;
            if(primeFlags[other])
                representations.push_back({prime, other});
        }
        cout << x << " has " << representations.size() << " representation(s)" << endl;
        for(pair<int, int> rep: representations)
            cout << rep.first << "+" << rep.second << endl;
        cout << endl;
    }
}