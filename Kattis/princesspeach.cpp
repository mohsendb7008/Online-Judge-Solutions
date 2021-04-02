#include <bits/stdc++.h>
using namespace std;

// Saving Princess Peach

int n, m, x;
bool obs[103];

int main(){
    cin >> n >> m;
    while(m--)
        cin >> x, obs[x] = 1;
    for(int i = 0; i < n; i++)
        if(!obs[i])
            cout << i << endl;
    cout << "Mario got " << count(obs, obs + n, 1) << " of the dangerous obstacles." << endl;
}