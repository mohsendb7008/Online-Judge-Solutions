#include <bits/stdc++.h>
using namespace std;

// Wine trading in Gergovia

int n;
long long int a[100003];

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        long long int ans = 0;
        for(int i = 0; i < n-1; i++){
            ans += abs(a[i]);
            a[i+1] += a[i];
        }
        cout << ans << endl;
    }
}