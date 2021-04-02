#include <bits/stdc++.h>
using namespace std;

// Neighborhood Watch

#define num long long int

num n, k, x, ans;
vector<num> safe;

int main(){
    cin >> n >> k;
    ans = (n * (n-1)) / 2 + k;
    safe.push_back(0);
    while(k--)
        cin >> x, safe.push_back(x);
    safe.push_back(n+1);
    for(int i = 0; i < safe.size() - 1; i++){
        num bet = safe[i + 1] - safe[i] - 1;
        if(bet >= 2)
            ans -= (bet * (bet-1)) / 2;
    }
    cout << ans << endl;
}