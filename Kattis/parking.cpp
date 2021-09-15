#include <bits/stdc++.h>
using namespace std;

// Parking

int price[3], cars[100];

int main(){
    cin >> price[0] >> price[1] >> price[2], price[1] *= 2, price[2] *= 3;
    for(int i = 0; i < 3; i++){
        int u, v;
        cin >> u >> v;
        for(int j = u; j < v; j++)
            cars[j]++;
    }
    int ans = 0;
    for(int i = 0; i < 100; i++)
        if(cars[i])
            ans += price[cars[i] - 1];
    cout << ans << endl;
}