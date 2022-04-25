#include <bits/stdc++.h>
using namespace std;

// Social Distancing

int mark[1003];

int main(){
    int s, n;
    cin >> s >> n;
    while(n--){
        int x;
        cin >> x;
        mark[x-1] = 1;
    }
    int ans = 0;
    for(int i = 0; i < s; i++){
        if(!mark[i] && !mark[(i - 1 + s) % s] && !mark[(i + 1) % s]){
            mark[i] = 1;
            ans++;
        }
    }
    cout << ans << endl;
}