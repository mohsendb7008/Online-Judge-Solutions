#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
priority_queue<int, vector<int>, greater<int>> jobs;

int main(){
    cin >> n;
    for(int day = 1; day <= n; day++){
        int k;
        cin >> k;
        while(k--){
            int job;
            cin >> job;
            jobs.push(day + job - 1);
        }
        while(!jobs.empty()){
            int job = jobs.top();
            jobs.pop();
            if(job >= day){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}