#include <bits/stdc++.h>
using namespace std;

// Counting Chocolate

int n, a[1000], sum = 0;
bool dp[50001];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    if(sum % 2){
        cout << "NO" << endl;
        return 0;
    }
    sum /= 2;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int w = sum; w >= 0; w--)
            if(dp[w] && w + a[i] <= sum){
                if(w + a[i] == sum){
                    cout << "YES" << endl;
                    return 0;
                }
                dp[w + a[i]] = 1;
            }
    }
    cout << "NO" << endl;
}