#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n;
char s[maxn], ans[maxn];

int main(){
    cin >> s, n = strlen(s);
    int ptr = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '=')
            ptr = max(0, ptr - 1);
        else
            ans[ptr++] = s[i];
    }
    ans[ptr] = 0;
    cout << ans << endl;
}