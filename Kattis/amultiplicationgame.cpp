#include <bits/stdc++.h>
using namespace std;

// A Multiplication Game

#define P false
#define N true
#define num long long int

num n;
map<num, bool> memo;

bool dp(num p){
    if(p >= n)
        return P;
    if(memo.find(p) != memo.end())
        return memo[p];
    bool ans = P;
    for(num i = 2; i <= 9; i++)
        if(dp(p * i) == P){
            ans = N;
            break;
        }
    return memo[p] = ans;
}

int main(){
    while(cin >> n){
        memo.clear();
        cout << (dp(1) ? "Stan wins." : "Ollie wins.") << endl;
    }
}