#include <bits/stdc++.h>
using namespace std;

// Transit Card

int l, t, n;
int p[103], d[103];

pair<int, int> intervals[5003];

int psum[1000003];

inline int ptc(int origin, int a, int b){
    return psum[b-origin+1] - psum[a-origin];
}

int dp[5003][5003];

int cdp(int i, int origin){
    if(dp[i][origin] != -1)
        return dp[i][origin];
    int rorigin = origin == 0 ? 1 : intervals[origin].second+1;
    if(i == n + 1)
        return dp[i][origin] = ptc(rorigin, intervals[n].second+1, t);
    int ans = min(ptc(rorigin, i == 1 ? 1 : intervals[i-1].second+1, intervals[i].second) + 
                  cdp(i+1, origin), 
                  ptc(rorigin, i == 1 ? 1 : intervals[i-1].second+1, intervals[i].first-1) + 
                  cdp(i+1, i));
    return dp[i][origin] = ans;
}

int main(){
    cin >> l;
    for(int i = 0; i < l; i++)
        cin >> p[i];
    for(int i = 0; i < l-1; i++)
        cin >> d[i];
    cin >> t >> n;
    for(int i = 1; i <= n; i++)
        cin >> intervals[i].first >> intervals[i].second;
    psum[0] = 0;
    int ptr = 1;
    for(int i = 0; i < l-1; i++){
        if(ptr == t+1)
            break;
        while(ptr <= t && d[i]--){
            psum[ptr] = psum[ptr-1] + p[i];
            ptr++;
        }
    }
    for(; ptr <= t; ptr++)
        psum[ptr] = psum[ptr-1] + p[l-1];
    for(int i = 0; i <= n+1; i++)
        for(int j = 0; j <= n+1; j++)
            dp[i][j] = -1;
    cout << cdp(1, 0) << endl; 
}