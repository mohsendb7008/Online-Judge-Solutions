#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n;
num p[(1 << 17) + 3];

num solve(int i, int j){
    if(i == j)
        return p[i];
    int mid = (i + j) / 2;
    num m1 = 0, m2 = 0;
    for(int k = i; k <= j; k++){
        if(k <= mid)
            m1 = max(m1, p[k]);
        else
            m2 = max(m2, p[k]);
    }
    return max(m1 + solve(mid + 1, j), m2 + solve(i, mid));
}

int main(){
    cin >> n, n = 1 << n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    cout << solve(0, n - 1) << endl;
}