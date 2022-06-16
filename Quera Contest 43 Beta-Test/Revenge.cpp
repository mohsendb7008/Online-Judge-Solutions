#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, b, c, A, B, C, X, Y, T, P;
    cin >> a >> b >> c >> A >> B >> C >> X >> Y >> T >> P;
    long long int ans = 0;
    while(P--){
        char choose = 'a';
        long long int profit = A - a;
        if(B - b > profit){
            choose = 'b';
            profit = B - b;
        }
        if(T && C - c > profit){
            choose = 'c';
            profit = C - c;
        }
        if(choose == 'a'){
            a += X;
        }
        if(choose == 'b'){
            b += Y;
        }
        if(choose == 'c'){
            T--;
        }
        ans += profit;
    }
    cout << ans << endl;
}