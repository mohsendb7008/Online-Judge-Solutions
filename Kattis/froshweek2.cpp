#include <bits/stdc++.h>
using namespace std;

// Frosh Week

int n, m;
int a[200003], b[200003];

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(b, b+m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int i = n-1, j = m-1;
    int ans = 0;
    while(i >= 0 && j >= 0){
        if(b[j] <= a[i])
            i--, ans++;
        j--;
    }
    cout << ans << endl;
}