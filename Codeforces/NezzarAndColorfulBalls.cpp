#include <bits/stdc++.h>
using namespace std;

int n, a[103];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        fill_n(a, n, 0);
        int x;
        for(int i = 0; i < n; i++)
            cin >> x, a[x-1]++;
        cout << *max_element(a, a + n) << endl;
    }
}