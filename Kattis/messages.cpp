#include <bits/stdc++.h>
using namespace std;

// Messages from Outer Space

set<string> dict;
string line;
char message[50003];
int dp[50003];

int main(){
    while(1){
        cin >> line;
        if(line == "#")
            break;
        dict.insert(line);
    }
    while(1){
        cin >> line;
        if(line == "#")
            break;
        int n = line.size();
        for(int i = 0; i < n; i++)
            message[i] = line[i];
        while(message[n-1] != '|')
            cin >> message[n++];
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            dp[i] = dp[i + 1];
            string tmp = "";
            for(int k = 1; k <= 10; k++){
                if(i + k >= n)
                    break;
                tmp += message[i + k - 1];
                if(dict.find(tmp) != dict.end())
                    dp[i] = max(dp[i], 1 + dp[i + k]);
            }
        }
        cout << dp[0] << endl;
    }
}