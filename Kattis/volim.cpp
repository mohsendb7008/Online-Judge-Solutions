#include <bits/stdc++.h>
using namespace std;

// Volim

int p, n, t = 0;
pair<int, char> q[103];

int main(){
    cin >> p >> n, p--;
    for(int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    for(int i = 0; i < n; i++){
        t += q[i].first;
        if(t >= 210){
            cout << p + 1 << endl;
            return 0;
        }
        if(q[i].second == 'T')
            p = (p + 1) % 8;
    }
}