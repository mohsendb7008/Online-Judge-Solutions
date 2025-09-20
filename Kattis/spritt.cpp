#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int sum = 0;
    while(n--){
        int y;
        cin >> y;
        sum += y;
    }
    if (sum <= x)
        cout << "Jebb" << endl;
    else
        cout << "Neibb" << endl;
}