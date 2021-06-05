#include <bits/stdc++.h>
using namespace std;

#define num long long int 

const num mod = 1000000007;

const int maxn = 1e5 + 3;

int n;
num a[maxn], k;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    num sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        ans = (ans + ((a[i] * (a[i] + 1)) / 2) % mod) % mod;
    }
    if(k >= sum){
        cout << ans << endl;
        return 0;
    }
    ans = 0;
    sort(a, a + n + 1);
    num up = a[n], cnt = 1;
    int ptr = n-1;
    while(1){
        while(a[ptr] == up)
            ptr--, cnt++;
        num dif = up - a[ptr];
        if(k > cnt * dif){
            ans = (ans + (cnt * (((up * (up + 1)) / 2 - (a[ptr] * (a[ptr] + 1)) / 2) % mod)) % mod) % mod; 
            k -= cnt * dif;
            up -= dif;
        }
        else{
            for(int i = 0; i < cnt; i++){
                num m = k / cnt;
                if(i < k % cnt)
                    m++;
                num down = up - m;
                ans = (ans + (1 * (((up * (up + 1)) / 2 - (down * (down + 1)) / 2) % mod)) % mod) % mod; 
            }
            break;
        }   
    }
    cout << ans << endl;
}