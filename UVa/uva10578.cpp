#include <bits/stdc++.h>
using namespace std;

// The Game of 31

#define N true
#define P false

map<string, bool> memo;

bool dp(string state){
    if(memo.find(state) != memo.end())
        return memo[state];
    int sum = 0;
    for(int i = 0; i < 6; i++)
        sum += (4 - (state[i] - '0')) * (i + 1);
    for(int i = 0; i < 6; i++)
        if(state[i] != '0' && sum + i + 1 <= 31){
            string subp = state;
            subp[i]--;
            if(dp(subp) == P)
                return memo[state] = N;
        }
    return memo[state] = P;
}

int main(){
    string input;
    while(cin >> input){
        string state = "444444";
        for(char c : input)
            state[c - '1']--;
        bool ans = dp(state);
        if(input.size() % 2)
            ans = !ans;
        cout << input << " " << (ans ? 'A' : 'B') << endl;
    }
}