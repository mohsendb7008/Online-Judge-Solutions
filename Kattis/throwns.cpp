#include <bits/stdc++.h>
using namespace std;

// Game of Throwns

int n, k;
stack<int> actions; 
stack<int> ractions;

int main(){
    cin >> n >> k;
    while(k--){
        string x;
        cin >> x;
        if(x == "undo"){
            int m;
            cin >> m;
            while(m-- && !actions.empty())
                actions.pop();
            continue;
        }
        actions.push(stoi(x));
    }
    while(!actions.empty())
        ractions.push(actions.top()), actions.pop();
    int ans = 0;
    while(!ractions.empty())
        ans = (ans + ractions.top() + n * 10000) % n, ractions.pop();
    cout << ans << endl;
}