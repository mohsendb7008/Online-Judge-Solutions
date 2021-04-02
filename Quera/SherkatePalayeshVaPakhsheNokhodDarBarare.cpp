#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e5 + 3;

int n;
num m, a[maxn];

int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    num up = a[n], cnt = 1, ans = 0;
    int ptr = n-1;
    while(1){
        while(a[ptr] == up)
            ptr--, cnt++;
        num dif = up - a[ptr];
        if(m > cnt * dif)
            m -= cnt * dif, up -= dif;
        else{
            for(int i = 0; i < cnt; i++){
                num k = m / cnt;
                if(i < m % cnt)
                    k++;
                ans += (up - k) * (up - k);
            }
            break;
        }
    }
    while(ptr)
        ans += a[ptr] * a[ptr], ptr--;
    cout << ans << endl;
}