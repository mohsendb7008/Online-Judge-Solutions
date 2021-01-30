#include <bits/stdc++.h>
using namespace std;

bool dp[103][13];

int main(){
    for(int i = 1; i < 10; i++)
        dp[0][i] = 1;
    for(int d = 1; d < 10; d++)
        for(int i = 1; i <= 100; i++){
            for(int j = 0; j < 10; j++){
                if(i - (10 * j + d) >= 0 && dp[i - (10 * j + d)][d]){
                    dp[i][d] = 1;
                    break;
                }
                if(i - (10 * d + j) >= 0 && dp[i - (10 * d + j)][d]){
                    dp[i][d] = 1;
                    break;
                }   
            }
        }
    int t, q, d, x;
    cin >> t;
    while(t--){
        cin >> q >> d;
        while(q--){
            cin >> x;
            if(x > 100)
                cout << "YES" << endl;
            else
                cout << (dp[x][d] ? "YES" : "NO") << endl;
        }
    }
}