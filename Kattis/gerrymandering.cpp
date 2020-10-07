#include <bits/stdc++.h>
using namespace std;

// Gerrymandering

int P, D;
int A[1003], B[1003];
int wa = 0, wb = 0, sum = 0;

int main(){
    cout << fixed;
    cout << setprecision(10);
    cin >> P >> D;
    fill_n(A, D, 0);
    fill_n(B, D, 0);
    int d, a, b, w;
    while(P--){
        cin >> d >> a >> b;
        A[d-1] += a;
        B[d-1] += b;
        sum += a + b;
    }
    for(int i = 0; i < D; i++){
        w = (A[i] + B[i]) / 2 + 1;
        if(A[i] > B[i]){
            wa += A[i] - w;
            wb += B[i];
            cout << "A " << A[i] - w << " " << B[i] << endl;
        }
        else{
            wa += A[i];
            wb += B[i] - w;
            cout << "B " << A[i] << " " << B[i] - w << endl;
        }
    }
    cout << double(abs(wa - wb)) / sum << endl;
}