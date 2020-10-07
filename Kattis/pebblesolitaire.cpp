#include <bits/stdc++.h>
using namespace std;

// Pebble Solitaire

map<string, int> memo;

int dp(string state){
    if(memo.find(state) != memo.end())
        return memo[state];
    int ans = count(state.begin(), state.end(), 'o');
    for(int i = 0; i < 10; i++){
        string sub = state.substr(i, 3);
        if(sub == "oo-")
            ans = min(ans, dp(state.substr(0, i) + "--o" + (i + 3 < 12 ? state.substr(i+3, 12-i-3) : "")));
        else if(sub == "-oo")
            ans = min(ans, dp(state.substr(0, i) + "o--" + (i + 3 < 12 ? state.substr(i+3, 12-i-3) : "")));
    }
    return memo[state] = ans;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cout << dp(s) << endl;
    }
}