#include <bits/stdc++.h>
using namespace std;

// The Magical 3

int main(){
    long long int n, ans;
    while(1){
        cin >> n;
        if(!n)
            break;
        if(n == 1 || n == 2)
            cout << "No such base" << endl;
        else if(n == 3)
            cout << 4 << endl;
        else{
            n -= 3, ans = LLONG_MAX;
            long long int u = sqrt(n);
            for(long long int i = 1; i <= u; i++)
                if(n % i == 0){
                    if(i >= 4)
                        ans = min(ans, i);
                    if(n / i >= 4)
                        ans = min(ans, n / i);
                }
            if(ans == LLONG_MAX)
                cout << "No such base" << endl;
            else 
                cout << ans << endl;   
        }
    }
}