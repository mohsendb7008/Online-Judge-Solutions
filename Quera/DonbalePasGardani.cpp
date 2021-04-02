#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, taken[1000001];
vector<int> seq[13];

void track(int i){
    if(i == n){
        ans++;
        return;
    }
    for(int j : seq[i])
        if(!taken[j]){
            taken[j] = 1;
            track(i + 1);
            taken[j] = 0;
        }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x;
        while(x--)
            cin >> y, seq[i].push_back(y);
    }
    track(0);
    cout << ans << endl;
}