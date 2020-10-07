#include <bits/stdc++.h>
using namespace std;

// Zigzag

int n, a[1000003];

int zigzag(bool inc){
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(inc && a[i] < a[i-1])
            inc = false, ans++;
        if(!inc && a[i] > a[i-1])
            inc = true, ans++;
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << max(zigzag(true), zigzag(false)) << endl;
}