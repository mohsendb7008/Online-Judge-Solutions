#include <bits/stdc++.h>
using namespace std;

string s;
int n;
bool dp[103][103];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s, n = s.size();
        for(int i = n; i >= 0; i--)
            for(int open = 0; open <= n; open++){
                if(i == n)
                    dp[i][open] = !open;
                else{
                    dp[i][open] = 0;
                    if(s[i] != ')' && open < n)
                        dp[i][open] = dp[i][open] || dp[i + 1][open + 1];
                    if(s[i] != '(' && open)
                        dp[i][open] = dp[i][open] || dp[i + 1][open - 1];
                }
            }
        cout << (dp[0][0] ? "YES" : "NO") << endl;
    }
}
