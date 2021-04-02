#include <bits/stdc++.h>
using namespace std;

// I Hate The Number Nine

#define mod 1000000007

long long int fast_power(long long int a, long long int b){
    if(b == 0)
        return 1;
    if(b % 2 == 1)
        return (a * fast_power(a, b-1)) % mod;
    long long int half = fast_power(a, b / 2);
    return (half * half) % mod;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int d;
        cin >> d;
        cout << (8 * fast_power(9, d-1)) % mod << endl;
    }
}