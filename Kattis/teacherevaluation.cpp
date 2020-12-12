#include <bits/stdc++.h>
using namespace std;

// Teacher Evaluation

int n, p, x, sum = 0;

int main(){
    cin >> n >> p;
    for(int i = 0; i < n; i++)
        cin >> x, sum += x;
    if(p == 100){
        cout << "impossible" << endl;
        return 0;
    }
    for(int ans = 1; 1; ans++){
        int need = (n + ans) * p - sum;
        if(need <= ans * 100){
            cout << ans << endl;
            return 0;
        }
    }
}