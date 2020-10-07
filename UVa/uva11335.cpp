#include <bits/stdc++.h>

using namespace std;

// Discrete Pursuit

double a, u, v;

inline int solve(int a, int u){
    return ceil((2 * u - 1 + sqrt((1 - 2 * u) * (1 - 2 * u) + 8 * a)) / 2);
}

int main(){
    while(cin >> a >> u >> v)
        cout << (a ? max(solve(a, u), solve(0, v)) : 0) << endl;
}