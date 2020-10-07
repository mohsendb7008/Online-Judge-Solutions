#include <bits/stdc++.h>
using namespace std;

// Brownie Points I

const int maxn = 2e4 + 3;

int n, ans1, ans2;
double x[maxn], y[maxn], a, b;

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        ans1 = ans2 = 0;
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        a = x[n/2], b = y[n/2];
        for(int i = 0; i < n; i++){
            if(x[i] == a || y[i] == b)
                continue;
            if((x[i] - a) * (y[i] - b) > 0)
                ans1++;
            else
                ans2++;
        }
        cout << ans1 << " " << ans2 << endl;
    }
}