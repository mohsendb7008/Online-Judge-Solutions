#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a){
        cout << "unique" << endl;
    }else{
        if(b){
            cout << "invalid" << endl;
        }else{
            cout << "infinite" << endl;
        }
    }
}