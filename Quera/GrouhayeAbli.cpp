#include <bits/stdc++.h>
using namespace std;

#define num long long int

num dp[103][103];

num modpow(num a, num b, num mod){
    if(!b){
        return a % mod;
    }
    if(b % 2){
        return ((a) % mod * modpow(a, b - 1, mod)) % mod;
    }
    num div = modpow(a, b / 2, mod);
    return (div * div) % mod;
}

inline bool fermatPrime(num n){
    for(int r = 0; r < 1000000; r++){
        num a = (((num)rand()) * rand()) % (n - 3) + 2;
        if(modpow(a, n-1, n) != 1){
            return false;
        }
    }
    return true;
}

inline num pSqrt(num n){
    num lo = 2, hi = n-1;
    while(lo < hi){
        num mid = (lo + hi) / 2 + (lo + hi) % 2;
        if(mid <= 1000000000 && mid * mid <= n){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    for(int i = -1; i < 2; i++){
        if((lo + i) * (lo + i) == n){
            return lo + i;
        }
    }
    return -1;
}

int main(){
    num n;
    cin >> n;
    for(int a = 1; a <= 100; a++){
        dp[0][a] = 1;
    }
    for(int sum = 1; sum <= 100; sum++){
        for(int a = sum; a >= 1; a--){
            if(!(sum - a) || sum - a >= a){
                dp[sum][a] = dp[sum - a][a];
            }
            if(a + 1 <= sum){
                dp[sum][a] += dp[sum][a + 1];
            }
        }
    }
    num ans = 1;
    for(num i = 2; i <= 1000000 && n > 1; i++){
        num counter = 0;
        while(!(n % i)){
            counter++;
            n /= i;
        }
        ans *= dp[counter][1];
    }
    if(n > 1){
        if(!fermatPrime(n)){
            num sq = pSqrt(n);
            if(sq != -1){
                bool sqPrime = true;
                for(int i = 2; i < min(sq, 100000ll); i++){
                    if(!(sq % i)){
                        sqPrime = false;
                        break;
                    }
                }
                if(sqPrime){
                    ans *= dp[2][1];
                }
            }
        }
    }
    cout << ans << endl;
}