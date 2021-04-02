#include <bits/stdc++.h>
using namespace std;

int f(int i){
    if(!i)
        return 5;
    int s = f(i-1);
    if(i % 2)
        return s * s;
    return s - 21;
}

int main(){
    int n;
    cin >> n;
    cout << f(n) << endl;
}