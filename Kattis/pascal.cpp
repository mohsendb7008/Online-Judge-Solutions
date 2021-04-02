#include <bits/stdc++.h>
using namespace std;

// Pascal

int n;

int main(){
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    int spf = n, up = sqrt(n);
    for(int p = 2; p <= up; p++)
        if(!(n % p)){
            spf = p;
            break;
        }
    cout << n - n / spf << endl;
}