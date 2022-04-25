#include <bits/stdc++.h>
using namespace std;

// RSA Mistake

const int MAX_P = 1000000;

int prime_flag[MAX_P + 1];
vector<int> primes;

inline void init(){
    for(int i = 2; i <= MAX_P; i++){
        if(!prime_flag[i]){
            primes.push_back(i);
            for(int j = 2 * i; j <= MAX_P; j += i){
                prime_flag[j] = 1;
            }
        }
    }
}

inline map<long long int, int> factorize(long long int n){
    map<long long int, int> result;
    for(int i = 0; n > 1 && i < primes.size(); i++){
        int prime = primes[i];
        while(!(n % prime)){
            n = n / prime;
            result[prime]++;
        }
    }
    if(n > 1){
        result[n]++;
    }
    return result;
}

int main(){
    init();
    long long int a, b;
    cin >> a >> b;
    map<long long int, int> x = factorize(a), y = factorize(b);
    if(x.size() == 1 && begin(x)->second == 1 && y.size() == 1 && begin(y)->second == 1 && a != b){
        cout << "full credit" << endl;
        return 0;
    }
    map<long long int, int> merge;
    for(auto it : x){
        merge[it.first] += it.second;
    }
    for(auto it : y){
        merge[it.first] += it.second;
    }
    for(auto it : merge){
        if(it.second > 1){
            cout << "no credit" << endl;
            return 0;
        }
    }
    cout << "partial credit" << endl;
}