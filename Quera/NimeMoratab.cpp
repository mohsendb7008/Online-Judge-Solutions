#include <bits/stdc++.h>
using namespace std;

int n, a, ans = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a, ans += (a != i);
    cout << (ans == 2 ? "YES" : "NO") << endl;
}