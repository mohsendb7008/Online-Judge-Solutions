#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 3;
 
int n, k, a[maxn];
 
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ptr = 0;
    int m = 0;
    while(k--){
        while(ptr < n && a[ptr] - m == 0)
            ptr++;
        if(ptr == n)
            cout << 0 << endl;
        else{
            cout << a[ptr] - m << endl;
            m += a[ptr] - m;
        }
    }
}