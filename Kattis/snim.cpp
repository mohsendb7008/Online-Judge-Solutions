#include <bits/stdc++.h>
using namespace std;

// S-Nim

int k, a[103], sg[10003];
set<int> mex;

int main(){
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> a[i];
    for(int i = 0; i <= 10000; i++){
        mex.clear();
        for(int j = 0; j < k; j++)
            if(i - a[j] >= 0)
                mex.insert(sg[i - a[j]]);
        for(int j = 0; 1; j++)
            if(mex.find(j) == mex.end()){
                sg[i] = j;
                break;
            }
    }
    int m;
    cin >> m;
    while(m--){
        cin >> k;
        int x, ans = 0;
        while(k--)
            cin >> x, ans = ans ^ sg[x];
        cout << (ans ? 'W' : 'L');           
    }   
}