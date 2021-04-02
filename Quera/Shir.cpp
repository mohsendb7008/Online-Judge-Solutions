#include <bits/stdc++.h>
using namespace std;

int cap[3], vis[23][23][23];
set<int> ans;

void dfs(vector<int> s){
    vis[s[0]][s[1]][s[2]] = 1;
    if(!s[0])
        ans.insert(s[2]);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(i != j){
                int d = min(s[i], cap[j] - s[j]);
                vector<int> t = s;
                t[i] -= d, t[j] += d;
                if(!vis[t[0]][t[1]][t[2]])
                    dfs(t);
            }
}

int main(){
    for(int i = 0; i < 3; i++)
        cin >> cap[i];
    vector<int> s{0, 0, cap[2]};
    dfs(s);
    for(int a : ans)
        cout << a << " ";
    cout << endl;
}