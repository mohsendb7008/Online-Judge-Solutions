#include <bits/stdc++.h>
using namespace std;

// Making Palindromes

int n, N;
char s[203];

#define num long long int
const num mod = 1000000007;

num dp[203][203][203];

int main(){
    cin >> n;
    cin >> s;
    for(int i = 0; i <= n; i++)
        for(int lptr = 0; lptr <= n; lptr++)
            for(int rptr = lptr; rptr <= n; rptr++){
                if(i == 0)
                    dp[i][lptr][rptr] = lptr == rptr;
                else{
                    num ans = 0;
                    for(char c = 'A'; c <= 'Z'; c++){
                        if(rptr - lptr > 1){
                            if(s[lptr] == c && s[rptr-1] == c)
                                ans = (ans + dp[i-1][lptr+1][rptr-1]) % mod;
                            else if(s[lptr] == c)
                                ans = (ans + dp[i-1][lptr+1][rptr]) % mod;
                            else if(s[rptr-1] == c)
                                ans = (ans + dp[i-1][lptr][rptr-1]) % mod;
                            else
                                ans = (ans + dp[i-1][lptr][rptr]) % mod;
                        }
                        else if(rptr - lptr == 1){
                            if(s[lptr] == c)
                                ans = (ans + dp[i-1][lptr+1][rptr]) % mod;
                            else
                                ans = (ans + dp[i-1][lptr][rptr]) % mod;
                        }
                        else ans = (ans + dp[i-1][lptr][rptr]) % mod;
                    }
                    dp[i][lptr][rptr] = ans;
                }
            }
    cout << dp[n][0][n] << endl;
}