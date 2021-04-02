#include <bits/stdc++.h>
using namespace std;

// Explosion Exploit

int n, m, d;
map<pair<int, pair<string, string>>, double> memo;

double dp(int d, string mine, string opp){
    pair<int, pair<string, string>> state = {d, {mine, opp}};
    if(memo.find(state) != memo.end())
        return memo[state];
    if(d == 0)
        return memo[state] = opp[0] - '0' == m;
    if(opp[0] - '0' == m)
        return memo[state] = 1;
    double sum = 0;
    double den = 0;
    for(int i = 1; i <= 6; i++){
        int cnt = mine[i] - '0';
        if(cnt == 0)
            continue;
        string co = mine;
        co[i]--;
        co[i-1]++;
        sum += cnt * dp(d-1, co, opp);
        den += cnt;
    }
    for(int i = 1; i <= 6; i++){
        int cnt = opp[i] - '0';
        if(cnt == 0)
            continue;
        string co = opp;
        co[i]--;
        co[i-1]++;
        sum += cnt * dp(d-1, mine, co);
        den += cnt;
    }
    return memo[state] = sum / den; 
}

int main(){
    cin >> n >> m >> d;
    string mine = "0000000", opp = "0000000";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mine[x]++;
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        opp[x]++;
    }
    cout << fixed << setprecision(10) << dp(d, mine, opp) << endl;
}