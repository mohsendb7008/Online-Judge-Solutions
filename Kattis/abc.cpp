#include <bits/stdc++.h>
using namespace std;

// ABC

int a[4];
char c[4];

int main(){
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    cin >> c;
    for(int i = 0; i < 3; i++)
        cout << a[c[i]-'A'] << " ";
}