#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, q, a[maxn];

int main(){
    cin >> n >> q;
    int ones = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i], ones += a[i];
    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            if(a[x-1])
                ones--;
            else
                ones++;
            a[x-1] = 1-a[x-1];
        }
        else
            cout << (x <= ones) << endl;
    }
}