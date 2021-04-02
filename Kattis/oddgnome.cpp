#include <bits/stdc++.h>
using namespace std;

// Odd Gnome

int a[1003];

int main(){
    int n, g;
    cin >> n;
    while(n--){
        cin >> g;
        for(int i = 0; i < g; i++)
            cin >> a[i];
        for(int i = 1; i < g-1; i++)
            if(a[i] != a[i-1] + 1){
                cout << i + 1 << endl;
                break;
            }
    }
}