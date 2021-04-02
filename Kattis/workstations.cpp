#include <bits/stdc++.h>
using namespace std;

// Assigning Workstations

const int maxn = 3e5 + 3;

int n, m;
pair<int, int> pep[maxn];
priority_queue<int, vector<int>, greater<int>> wss;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> pep[i].first >> pep[i].second;
    sort(pep, pep + n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(!wss.empty() && pep[i].first - wss.top() > m)
            wss.pop();
        if(!wss.empty() && wss.top() <= pep[i].first)
            ans++, wss.pop();
        wss.push(pep[i].first + pep[i].second);
    }
    cout << ans << endl;
}