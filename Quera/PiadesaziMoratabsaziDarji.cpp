#include <bits/stdc++.h>
using namespace std;

int n, a[1503];

void sort(int i){
    int j = i, v = a[i];
    for(int k = 0; k < i; k++)
        if(a[k] > v){
            j = k;
            break;
        }
    for(int k = i; k > j; k--)
        a[k] = a[k-1];
    a[j] = v;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
        sort(i);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}