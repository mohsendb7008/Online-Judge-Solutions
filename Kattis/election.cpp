#include <bits/stdc++.h>
using namespace std;

// Election

#define num long long int
num c[53][53], po2[53];

num n, v1, v2, r;
double w;

int main(){
    for(int i = 0; i < 53; i++)
        for(int j = 0; j <= i; j++){
            if(i == j || j == 0)
                c[i][j] = 1;
            else 
                c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    po2[0] = 1;
    for(int i = 1; i < 53; i++)
        po2[i] = 2 * po2[i-1];
    int t;
    cin >> t;
    while(t--){
        cin >> n >> v1 >> v2 >> w, r = n - v1 - v2, w /= 100;
        if(v1 > n / 2){
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
            continue;
        }
        if(v1 + r <= n / 2){
            cout << "RECOUNT!" << endl;
            continue;
        }
        num need = n / 2 - v1 + 1;
        double p = 0;
        for(num x = need; x <= r; x++)
            p += c[r][x];
        p /= po2[r];
        if(p > w){
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
            continue;
        }
        cout << "PATIENCE, EVERYONE!" << endl;
    }
}