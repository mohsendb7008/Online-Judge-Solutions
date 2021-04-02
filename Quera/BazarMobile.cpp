#include <bits/stdc++.h>
using namespace std;

int n, p[1003], q[1003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i] >> q[i];
    int ans = n;
    for(int i = 0; i < n; i++){
        bool useless = 0;
        for(int j = 0; j < n; j++)
            if(i != j && p[j] <= p[i] && q[j] >= q[i]){
                useless = 1;
                break;
            }
        ans -= useless;
    }
    cout << ans << endl;
}