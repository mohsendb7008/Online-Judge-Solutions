#include <bits/stdc++.h>
using namespace std;

// Power Strings

const int maxn = 2e6 + 3;

int n, m;
string t, p;
int lcp[maxn];

int main(){
    while(1){
        cin >> p;
        if(p == ".")
            break;
        t = p + p;
        n = t.size(), m = p.size();
        int ans = 0, i = 0, j = 1;
        while(j < m){
            if(p[j] == p[i])
                lcp[j] = i + 1, j++, i++;
            else if(i)
                i = lcp[i - 1];
            else
                lcp[j] = 0, j++;
        }
        i = 0, j = 0;
        while(i < n){
            if(t[i] == p[j]){
                i++, j++;
                if(j == m){
                    ans++;
                    j = lcp[j - 1];
                }
            }
            else if(j)
                j = lcp[j - 1];
            else
                i++;
        }
        cout << ans - 1 << endl;
    }
}