#include <bits/stdc++.h>
using namespace std;

// Math Homework

int main(){
    int b, d, c, l;
    cin >> b >> d >> c >> l;
    bool ans = false;
    for(int i = 0; i <= l / b; i++)
        for(int j = 0; j <= l / d; j++)
            for(int k = 0; k <= l / c; k++)
                if(i * b + j * d + k * c == l){
                    ans = true;
                    cout << i << " " << j << " " << k << endl;
                }
    if(!ans)
        cout << "impossible" << endl;
}