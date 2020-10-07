#include <bits/stdc++.h>
using namespace std;

// Association for Computing Machinery

int n, f, p[16];

int main(){
    cin >> n >> f;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    swap(p[0], p[f]);
    sort(p+1, p+n);
    int t = 0, ans = 0, penalty = 0;
    for(int i = 0; i < n; i++){
        t += p[i];
        if(t > 300)
            break;
        ans++, penalty += t;
    }
    cout << ans << " " << penalty << endl;
}