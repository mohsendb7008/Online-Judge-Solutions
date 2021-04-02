#include<bits/stdc++.h>
using namespace std;

// Birds on a Wire

int l, d, n, birds[20003];

int main(){
    cin >> l >> d >> n;
    if(l < 12){
        cout << 0 << endl;
        return 0;
    }
    if(!n){
        cout << (l - 12) / d + 1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        cin >> birds[i];
    sort(birds, birds + n);
    int ans = 0;
    for(int i = 0; i < n-1; i++)
        if(birds[i+1] - birds[i] >= 2 * d)
            ans += (birds[i+1] - birds[i] - 2 * d) / d + 1;
    if(birds[0] - 6 >= d)
        ans += (birds[0] - 6 - d) / d + 1;
    if(l - 6 - birds[n-1] >= d)
        ans += (l - 6 - birds[n-1] - d) / d + 1;
    cout << ans << endl;
}