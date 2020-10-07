#include <bits/stdc++.h>
using namespace std;

// Diving for gold

#define num long long int

int T, w, n;
num dp[33][1003], trace[33][1003];
pair<int, num> treasures[33];
vector<int> collecteds;

num cdp(int i, int t){
    if(i == -1)
        return 0;
    if(dp[i][t] != -1)
        return dp[i][t];
    num ans1 = cdp(i-1, t);
    int tmp = t - 3 * w * treasures[i].first; 
    num ans2 = -1;
    if(tmp >= 0)
        ans2 = cdp(i-1, tmp) + treasures[i].second;
    if(ans1 >= ans2){
        dp[i][t] = ans1;
        trace[i][t] = 0;
    }
    else{
        dp[i][t] = ans2;
        trace[i][t] = 1;
    }
    return dp[i][t];
}

int main(){

    while(true){
        for(int i = 0; i < 33; i++)
            for(int j = 0; j < 1003; j++){
                dp[i][j] = -1;
                trace[i][j] = -1;
            }
        
        cin >> T >> w >> n;
        for(int i = 0; i < n; i++)
            cin >> treasures[i].first >> treasures[i].second;

        cout << cdp(n-1, T) << endl;
        collecteds.clear();
        for(int i = n-1; i >= 0; i--)
            if(trace[i][T]){
                collecteds.push_back(i);
                T -= 3 * w * treasures[i].first;
            }
        reverse(collecteds.begin(), collecteds.end());
        cout << collecteds.size() << endl;
        for(int i: collecteds)
            cout << treasures[i].first << " " << treasures[i].second << endl;
        string s;
        getline(cin, s);
        if(!getline(cin, s))
            break;
        cout << endl;
    }
}