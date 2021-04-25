#include <bits/stdc++.h>
using namespace std;

// Harshad Numbers

inline int digitsum(int a){
    int ans = 0;
    while(a)
        ans += a % 10, a /= 10;
    return ans;
}

int main(){
    int n;
    cin >> n;
    while(n % digitsum(n))
        n++;
    cout << n << '\n';
}