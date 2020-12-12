#include <bits/stdc++.h>
using namespace std;

// Field Trip

#define num long long int

const int maxn = 1e6 + 3;

int n, i = 0, ans1, ans2;
num a[maxn], sum3 = 0, psum = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i], sum3 += a[i];
    if(sum3 % 3){
        cout << -1 << endl;
        return 0;
    }
    sum3 /= 3;
    while(i < n && psum < sum3)
        psum += a[i], i++;
    if(psum == sum3)
        ans1 = i, psum = 0;
    else{
        cout << -1 << endl;
        return 0;
    }
    while(i < n && psum < sum3)
        psum += a[i], i++;
    if(psum == sum3)
        ans2 = i, psum = 0;
    else{
        cout << -1 << endl;
        return 0;
    }
    while(i < n)
        psum += a[i], i++;
    if(psum != sum3){
        cout << -1 << endl;
        return 0;
    }
    cout << ans1 << " " << ans2 << endl;
}