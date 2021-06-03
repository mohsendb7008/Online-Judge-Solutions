#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, m, a;
    cin >> n >> m >> a;
    long long int x = n / a + (n % a ? 1 : 0);
    long long int y = m / a + (m % a ? 1 : 0);
    cout << x * y << endl;
}