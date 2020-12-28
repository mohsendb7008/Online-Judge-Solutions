#include <bits/stdc++.h>
using namespace std;

// Cu Chi Tunnels

int n, deg[1003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> deg[i];
    for(int i = 1; i < n; i++){
        deg[i]--;
        int p = -1;
        for(int j = i - 1; j >= 0; j--)
            if(deg[j]){
                p = j;
                break;
            }
        if(p == -1){
            cout << "NO" << endl;
            return 0;
        }
        deg[p]--;
    }
    cout << (accumulate(deg, deg + n, 0) ? "NO" : "YES") << endl;
}