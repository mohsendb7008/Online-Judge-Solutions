#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, m, x[maxn], minl[maxn], maxl[maxn], minr[maxn], maxr[maxn];
string instructions;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> instructions;
        x[0] = 0;
        for(int i = 1; i <= n; i++){
            if(instructions[i-1] == '+')
                x[i] = x[i-1] + 1;
            else
                x[i] = x[i-1] - 1;
        }
        minl[0] = maxl[0] = x[0];
        for(int i = 1; i <= n; i++)
            minl[i] = min(minl[i-1], x[i]), maxl[i] = max(maxl[i-1], x[i]);
        minr[n] = maxr[n] = x[n];
        for(int i = n-1; i >= 0; i--)
            minr[i] = min(minr[i+1], x[i]), maxr[i] = max(maxr[i+1], x[i]);
        while(m--){
            int l, r;
            cin >> l >> r;
            if(r == n)
                cout << maxl[l-1] - minl[l-1] + 1 << endl;
            else{
                int a1 = minl[l-1], b1 = maxl[l-1];
                int a2 = minr[r+1] - x[r] + x[l-1], b2 = maxr[r+1] - x[r] + x[l-1];
                int a3 = max(a1, a2), b3 = min(b1, b2);
                int ans = b1 + b2 - (a1 + a2) + 2;
                if(a3 <= b3)
                    ans -= b3 - a3 + 1;
                cout << ans << endl;
            }
        }
    }   
}