#include <bits/stdc++.h>
using namespace std;

int a, b, x, ans = 0;

int main(){
    cin >> a >> b >> x;
    for(int i = 1; i <= a; i++)
        if(!(a % i))
            for(int j = 1; j <= b; j++)
                if(!(b % j) && i + j <= x)
                    ans++;
    cout << ans << endl;
}