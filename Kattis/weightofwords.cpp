#include <bits/stdc++.h>
using namespace std;

// The Weight Of Words

int l, w;
char trace[43][1003];

char dp(int i, int w){
    if(trace[i][w] != '*')
        return trace[i][w];
    char ans = '.';
    if(i == 0){
        for(char c = 'a'; c <= 'z'; c++)
            if(c - 'a' + 1 == w){
                ans = c;
                break;
            }
        return trace[i][w] = ans;
    }
    for(char c = 'a'; c <= 'z'; c++)
        if(c - 'a' + 1 <= w && dp(i-1, w-c+'a'-1) != '.'){
            ans = c;
            break;
        }
    return trace[i][w] = ans;
}

int main(){
    for(int i = 0; i < 43; i++)
        for(int j = 0; j < 1003; j++)
            trace[i][j] = '*';
    cin >> l >> w;
    if(dp(l-1, w) == '.'){
        cout << "impossible";
        return 0;
    }
    while(l--){
        cout << trace[l][w];
        w -= trace[l][w] - 'a' + 1;
    }
}