#include <bits/stdc++.h>
using namespace std;

// The Citrus Intern

#define num long long int

int n;
vector<int> childs[100003];
num c[100003];
num dp[100003][4];

num cdp(int node, int state){
    if(dp[node][state] != -1)
        return dp[node][state];
    num ans;
    if(childs[node].empty()) // leaf
        ans = state ? c[node] : 0;
    else if(state == 0){
        ans = 0;
        for(int child : childs[node])
            ans += cdp(child, 2);
    }
    else if(state == 1){
        ans = c[node];
        for(int child : childs[node])
            ans += cdp(child, 0);
    }
    else{
        num sum = 0;
        for(int child : childs[node])
            sum += cdp(child, 2);
        ans = cdp(node, 1);
        for(int child : childs[node])
            ans = min(ans, sum - cdp(child, 2) + cdp(child, 1));
    }
    return dp[node][state] = ans;
}

bool root[100003];

int main(){
    cin >> n;
    fill_n(root, n, true);
    int l, x;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        cin >> l;
        while(l--){
            cin >> x;
            root[x] = false;
            childs[i].push_back(x);
        }
    }
    for(int i = 0; i < n; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
    }
    for(int node = 0; node < n; node++)
        if(root[node]){
            cout << cdp(node, 2) << endl;
            break;
        }
}