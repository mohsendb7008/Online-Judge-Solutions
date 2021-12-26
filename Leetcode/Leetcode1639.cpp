#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define mod 1000000007

class Solution {
public:
    
    num dp[1003][1003];
    vector<string> words;
    string target;
    vector<int> letters[26 + 3];
    int cnt[26 + 3][1003];
    
    num cdp(int i, int k){
        if(dp[i][k] != -1)
            return dp[i][k];
        if(i == target.size())
            return dp[i][k] = 1;
        if(k >= words[0].size())
            return dp[i][k] = 0;
        int j = target[i] - 'a';
        auto itr = lower_bound(letters[j].begin(), letters[j].end(), k);
        if(itr == letters[j].end())
            return dp[i][k] = 0;
        dp[i][k] = ((cdp(i + 1, (*itr) + 1) * cnt[j][*itr]) % mod + cdp(i, (*itr) + 1)) % mod;
        return dp[i][k];
    }
    
    int numWays(vector<string>& words1, string target1) {
        this->words = words1;
        this->target = target1;
        for(string str : words){
            for(int i = 0; i < str.size(); i++)
                letters[str[i] - 'a'].push_back(i), cnt[str[i] - 'a'][i]++;
        }
        for(int i = 0; i < 26; i++)
            sort(letters[i].begin(), letters[i].end());
        for(int i = 0; i < 1003; i++)
            for(int k = 0; k < 1003; k++)
                dp[i][k] = -1;
        return cdp(0, 0);
    }
};