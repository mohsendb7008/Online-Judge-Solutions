#include <bits/stdc++.h>
using namespace std;

int n, k;
string str;
long long int dp[3][9][513];

const int mod = 1000000007;

int main(){
    cin >> n >> k >> str;
    if(k % 2){
        cout << 0 << endl;
        return 0;
    }
    for(int i = n; i >= 0; i--){
        for(int j = 0; j <= k/2; j++){
            for(int s = 1; s < (1 << (k/2 + 1)); s++){
                if(i == n){
                    dp[i % 2][j][s] = (j == k/2) && (s == 1);
                }else{
                    dp[i % 2][j][s] = dp[(i+1) % 2][j][s];
                    if(str[i] == '('){
                        if(j < k/2){
                            dp[i % 2][j][s] += dp[(i+1) % 2][j+1][s << 1];
                        }
                    }else if(str[i] == '['){
                        if(j < k/2){
                            dp[i % 2][j][s] += dp[(i+1) % 2][j+1][(s << 1) + 1];
                        }
                    }else if(str[i] == ')'){
                        if(s > 1 && !(s % 2)){
                            dp[i % 2][j][s] += dp[(i+1) % 2][j][s >> 1];
                        }
                    }else if(str[i] == ']'){
                        if(s > 1 && s % 2){
                            dp[i % 2][j][s] += dp[(i+1) % 2][j][s >> 1];
                        }
                    }
                    dp[i % 2][j][s] %= mod;
                }
            }
        }
    }
    cout << dp[0][0][1] << endl;
}