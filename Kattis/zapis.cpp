#include <bits/stdc++.h>
using namespace std;

// Zapis

// The problem author was a bad guy!
// You should notice that mod of 1e5 is different with 5 rightmost digits! Watch out 0-paddings :)

#define num long long int
#define mod 100000

bool flag = false;

int n;
char s[203];
num dp[203][203];
char opt[3]{'(', '[', '{'};
char opt2[3]{')', ']', '}'};

num cdp(int i, int j){
    if(j < i)
        return 1;
    if((j - i + 1) % 2 || s[i] == ')' || s[i] == ']' || s[i] == '}')
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    num ans = 0;
    for(int c = 0; c < 3; c++)
        if(s[i] == '?' || s[i] == opt[c])
            for(int k = j; k >= i+1; k-=2)
                if(s[k] == '?' || s[k] == opt2[c]){
                    num m = cdp(i+1, k-1) * cdp(k+1, j);
                    if(m >= mod)
                        flag = true;
                    m %= mod;
                    ans = ans + m;
                    if(ans >= mod)
                        flag = true;
                    ans %= mod;
                }
    return dp[i][j] = ans;
}

int main(){
    cin >> n >> s;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = -1;
    num ans = cdp(0, n-1);
    if(flag)
        printf("%05d", ans);
    else 
        cout << ans << endl;
}