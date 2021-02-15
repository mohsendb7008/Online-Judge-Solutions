#include <bits/stdc++.h>
using namespace std;

double fast_pow(double a, int b){
    if(!b)
        return 1;
    if(b % 2)
        return a * fast_pow(a, b - 1);
    double h = fast_pow(a, b / 2);
    return h * h;
}

int main(){
    double a;
    int b;
    cin >> a >> b;
    cout << fixed << setprecision(3) << fast_pow(a, b) << endl; 
}