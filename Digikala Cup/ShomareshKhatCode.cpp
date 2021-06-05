#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1000000007;

string note;
num min_, max_, dp[1003];

int main(){
    cin >> note >> min_ >> max_;
    int n = note.size();
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--){
        if(note[i] == '0')
            continue;
        num curr = 0;
        for(int j = i; j < n; j++){
            curr = 10 * curr + (note[j] - '0');
            if(curr >= max_)
                break;
            if(curr > min_)
                dp[i] = (dp[i] + dp[j+1]) % mod;
        }
    }
    cout << dp[0] << endl;
}