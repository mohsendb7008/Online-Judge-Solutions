#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e6 + 3;

int n, q;
num arr[maxn], ps[maxn];

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    partial_sum(arr, arr+n, ps);
    while(q--){
        int l, r;
        cin >> l >> r;
        if(l == 0)
            cout << ps[r] << endl;
        else
            cout << ps[r] - ps[l-1] << endl;
    }
}