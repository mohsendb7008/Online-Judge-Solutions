#include <bits/stdc++.h>
using namespace std;

int a[4], ans[4];

int main(){
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    int i = 0;
    while(1){
        a[(i + i) % 4]--, ans[i]++;
        if(!a[(i + i) % 4])
            break;
        i = (i + 1) % 4;
    }
    for(int i = 0; i < 4; i++)
        cout << ans[i] << " \n"[i == 4];
}