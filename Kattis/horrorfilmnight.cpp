#include <bits/stdc++.h>
using namespace std;

// Horror Film Night

int n, m;
int a[1000003], b[1000003];

int i = 0, j = 0, s = 0;

void selecta(){
    int cand = a[i];
    i++;
    while(j < m && b[j] < cand)
        j++;
    s = 2;
    if(j < m && b[j] == cand)
        s = 0, j++;
}

void selectb(){
    int cand = b[j];
    j++;
    while(i < n && a[i] < cand)
        i++;
   s = 1;
   if(i < n && a[i] == cand)
        s = 0, i++;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a+n), sort(b, b+m);
    int ans = 0;
    while(i < n && j < m){
        if(s == 0){
            if(a[i] == b[j])
                i++, j++;
            else if(a[i] < b[j])
                selecta();
            else
                selectb();
        }
        else if(s == 1)
            selecta();
        else if(s == 2)
            selectb();
        ans++;
    }
    if(i < n && s != 2)
        ans++;
    if(j < m && s != 1)
        ans++;
    cout << ans << endl;   
}