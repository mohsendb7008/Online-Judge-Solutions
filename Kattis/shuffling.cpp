#include <bits/stdc++.h>
using namespace std;

// Shuffling Along

int n, a[1003], tmp[1003];
bool out;

bool stop(){
    for(int i = 0; i < n; i++)
        if(a[i] != i)
            return false;
    return true;
}

void shuff(){
    int mid;
    if(!(n % 2))
        mid = (n - 1) / 2;
    else if(out)
        mid = (n - 1) / 2;
    else 
        mid = (n - 2) / 2;
    int lptr = 0, rptr = mid + 1, cptr = 0;
    if(out){
        while(lptr <= mid && rptr <= n - 1){
            tmp[cptr++] = a[lptr++];
            tmp[cptr++] = a[rptr++]; 
        }
        if(lptr <= mid)
            tmp[cptr++] = a[lptr++];
    }else{
        while(lptr <= mid && rptr <= n - 1){
            tmp[cptr++] = a[rptr++];
            tmp[cptr++] = a[lptr++];
        }
        if(rptr <= n-1)
            tmp[cptr++] = a[rptr++];
    }
    copy_n(tmp, n, a);
}

int main(){
    string s;
    cin >> n >> s;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    out = s == "out";
    iota(a, a + n, 0);
    int ans = 0;
    do{
        shuff();
        ans++;
    }while(!stop());
    cout << ans << endl;
}