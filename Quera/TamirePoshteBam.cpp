#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e6 + 3;

int n, mini[maxn];
num a[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    num ans = a[n-1];
    int ptr = n-1;
    mini[n-1] = ptr;
    for(int i = n-2; i >= 0; i--){
        if(a[i] < ans)
            ans = a[i], ptr = i;
        mini[i] = ptr;
    }
    ans = 0, ptr = 0;
    while(ptr < n)
        ans += a[mini[ptr]] * (mini[ptr] - ptr + 1), ptr = mini[ptr] + 1;
    cout << ans << endl;
}