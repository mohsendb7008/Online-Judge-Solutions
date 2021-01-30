#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 3;

int n, rdp[maxn][3], ldp[maxn][3];
string s;

int crdp(int i, int j){
    if(rdp[i][j] != -1)
        return rdp[i][j];
    int ans = 1;
    if(i < n){
        if((j && s[i] == 'R') || (!j && s[i] == 'L'))
            ans += crdp(i + 1, 1 - j);
    }
    return rdp[i][j] = ans;
}

int cldp(int i, int j){
    if(ldp[i][j] != -1)
        return ldp[i][j];
    int ans = 1;
    if(i){
        if((j && s[i - 1] == 'L') || (!j && s[i - 1] == 'R'))
            ans += cldp(i - 1, 1 - j);
    }
    return ldp[i][j] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j < 2; j++)
                rdp[i][j] = ldp[i][j] = -1;
        for(int i = 0; i <= n; i++)
            cout << crdp(i, 1) + cldp(i, 1) - 1 << " ";
        cout << endl;
    }
}