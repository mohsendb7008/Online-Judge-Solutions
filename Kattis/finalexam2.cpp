#include <bits/stdc++.h>
using namespace std;

// Final Exam

int n;
char a[1003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 1; i < n; i++)
        if(a[i-1] == a[i])
            ans++;
    cout << ans << endl;
}