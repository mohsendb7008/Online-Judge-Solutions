#include <bits/stdc++.h>
using namespace std;

// Beehives

#define EPS 1e-8

int n;
double x[103], y[103], d;

int main(){
    while(1){
        cin >> d >> n;
        if(!(d + n))
            break;
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        int sour = 0, sweet = 0;
        for(int i = 0; i < n; i++){
            bool s = false;
            for(int j = 0; j < n; j++)
                if(j != i && hypot(x[i] - x[j], y[i] - y[j]) < d + EPS){
                    s = true;
                    break;
                }
            if(s)
                sour++;
            else
                sweet++;
        }
        cout << sour << " sour, " << sweet << " sweet" << endl;
    }
}