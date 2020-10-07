#include <bits/stdc++.h>
using namespace std;

// Commando War

int n;
pair<int, int> a[1003];

int main(){
    int t = 1;
    while(1){
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a, a+n, [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second > p2.second;
        });
        int psum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            psum += a[i].first;
            ans = max(ans, psum + a[i].second);
        }
        cout << "Case " << t++ << ": " << ans << endl;
    }
}