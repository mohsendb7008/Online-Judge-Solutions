#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    double limit = double(1) / k;
    for(int n = 1; n <= 1000000000; n++){
        if(sin(n) >= 0 && sin(n) <= limit){
            cout << n << endl;
            break;
        }
    }
}