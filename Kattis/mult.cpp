// Mult!

#include <bits/stdc++.h>
using namespace std;

int main(){
    int first = -1;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(first == -1){
            first = x;
        }
        else if(!(x % first)){
            cout << x << endl;
            first = -1;
        }
    }
}