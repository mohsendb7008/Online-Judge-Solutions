#include <bits/stdc++.h>
using namespace std;

// Moliu Number Generator

#define num long long int

map<num, num> memo;

num solve(num n){
    if(memo.find(n) != memo.end())
        return memo[n];
    if(n % 2)
        return memo[n] = 1 + min(solve(n-1), 1 + solve((n+1)/2));
    return memo[n] = 1 + solve(n/2);
}

int main(){
    memo[0] = 0, memo[1] = 1;
    num n;
    while(cin >> n)
        cout << solve(n) << endl;
}