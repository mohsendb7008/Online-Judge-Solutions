#include <bits/stdc++.h>
using namespace std;

// Installing Apps

struct app{
    int d, s, index;
};

int n;
app apps[503];

int dp[503][10003];
bool trace[503][10003];

int cdp(int i, int s){
    if(i == -1)
        return 0;
    if(dp[i][s] != -1)
        return dp[i][s];
    dp[i][s] = cdp(i-1, s);
    trace[i][s] = false;
    if(s >= max(apps[i].d, apps[i].s)){
        int subp = cdp(i-1, s - apps[i].s);
        if(subp + 1 > dp[i][s]){
            dp[i][s] = subp + 1;
            trace[i][s] = true;
        }
    }
    return dp[i][s];
}

int main(){
    int S;
    cin >> n >> S;
    for(int i = 0; i < n; i++)
        cin >> apps[i].d >> apps[i].s, apps[i].index = i+1;
    sort(apps, apps+n, [](const app& a1, const app& a2){
        return a1.d - a1.s < a2.d - a2.s;
    });
    for(int i = 0; i < n; i++)
        for(int s = 0; s <= S; s++)
            dp[i][s] = -1;
    int ans = cdp(n-1, S);
    cout << ans << endl;
    if(ans){
        vector<int> path;
        for(int i = n - 1; i >= 0; i--){
            if(trace[i][S]){
                path.push_back(apps[i].index);
                S -= apps[i].s;
            } 
       }
        for(int ind : path)
            cout << ind << " ";
        cout << endl;
    }
}