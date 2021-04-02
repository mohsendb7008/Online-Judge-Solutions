#include <bits/stdc++.h>
using namespace std;

// Digit Sum

map<string, long long int> memo;

long long int dp(string num){
    if(memo.find(num) != memo.end())
        return memo[num];
    char a = num[0];
    string b = num.substr(1);
    string sub = "";
    if(a > '1')
        sub += a-1;
    for(int i = 0; i < b.size(); i++)
        sub += '9';
    return memo[num] = dp(sub) + dp(to_string(stoll(b))) + (a - '0') * (stoll(b) + 1);
}

int main(){
    memo["0"] = 0;
    for(int i = 1; i <= 9; i++)
        memo[to_string(i)] = i + memo[to_string(i-1)];
    int n;
    cin >> n;
    while(n--){
        long long int a, b;
        cin >> a >> b;
        cout << dp(to_string(b)) - (a == 0 ? 0 : dp(to_string(a-1))) << endl;
    }
}