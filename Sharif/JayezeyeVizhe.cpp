#include <bits/stdc++.h>
using namespace std;

int n, k, prevy = 0;
string s;

int main(){
    cin >> n >> k >> s, k = n-k;
    while(k){
        char ans = '.';
        int ind;
        for(int i = prevy; i < n - k + 1; i++)
            if(s[i] > ans)
                ans = s[i], ind = i;
        cout << ans;
        prevy = ind+1;
        k--;
    }
}