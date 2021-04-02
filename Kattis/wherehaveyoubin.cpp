#include <bits/stdc++.h>
using namespace std;

// Where Have You Bin?

map<char, int> id{{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};

int n, bin[153], need[5+3], sum[(1<<5)+3], dp[153][(1<<5)+3];
string bins, req;

int main(){
    cin >> bins;
    n = bins.size();
    for(int i = 0; i < n; i++)
        cin >> bin[i];
    int k, x;
    cin >> k;
    while(k--)
        cin >> x, bins[x - 1] = 'X', bin[x - 1] = 0;
    for(char c : bins)
        if(c != 'X')
            need[id[c]]++;
    cin >> req;
    for(char c : req)
        if(c != 'X')
            need[id[c]]++;
    for(int mask = 1; mask < (1 << 5); mask++)
        for(int i = 0; i < 5; i++)
            if(mask & (1 << i))
                sum[mask] += need[i];
    int all = 0;
    for(int i = 0; i < 5; i++)
        if(need[i])
            all += 1 << i;
    for(int i = 0; i < n; i++)
        for(int mask = 0; mask < (1 << 5); mask++){
            if((mask | all) != all)
                continue;
            if(!mask){
                dp[i][mask] = 0;
                for(int j = 0; j <= i; j++)
                    dp[i][mask] += bin[j];
            }
            else if(sum[mask] > i + 1)
                dp[i][mask] = -1;
            else{
                dp[i][mask] = INT_MAX;
                if(i && dp[i-1][mask] != -1)
                    dp[i][mask] = bin[i] +  dp[i-1][mask];
                for(int c = 0; c < 5; c++)
                    if(mask & (1 << c)){
                        int curr = 0, s = i - need[c];
                        for(int j = s + 1; j <= i; j++)
                            if(bins[j] != 'X' && id[bins[j]] != c)
                                curr += bin[j];
                        if(s >= 0 && dp[s][mask - (1 << c)] == -1)
                            continue;
                        dp[i][mask] = min(dp[i][mask], ((s >= 0) ? dp[s][mask - (1 << c)] : 0) + curr);
                    }
            }         
       }
    cout << dp[n - 1][all] << endl;      
}