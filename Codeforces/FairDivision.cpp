#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ones = 0, twos = 0, x;
        cin >> n;
        while(n--){
            cin >> x;
            if(x == 1)
                ones++;
            else
                twos++;
        }
        if(twos % 2){
            if(ones >= 2 && !(ones % 2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else{
             if(ones % 2)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}
