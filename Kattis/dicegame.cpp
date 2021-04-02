#include <bits/stdc++.h>
using namespace std;

// Dice Game

double exp(int a1, int b1, int a2, int b2){
    double ans = 0;
    for(int k1 = a1; k1 <= b1; k1++)
        for(int k2 = a2; k2 <= b2; k2++)
            ans += double(k1 + k2) / double((b1 - a1 + 1) * (b2 - a2 + 1));
    return ans;
}

int main(){
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    double e1 = exp(a1, b1, a2, b2);
    cin >> a1 >> b1 >> a2 >> b2;
    double e2 = exp(a1, b1, a2, b2);
    if(fabs(e1 - e2) < 1e-9)
        cout << "Tie" << endl;
    else if(e1 > e2)
        cout << "Gunnar" << endl;
    else
        cout << "Emma" << endl; 
}