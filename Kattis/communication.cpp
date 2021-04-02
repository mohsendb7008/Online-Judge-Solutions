#include <bits/stdc++.h>
using namespace std;

// Jumbled Communication

int calc(int x){
    int ans = x << 1;
    if(ans & (1 << 8))
        ans -= 1 << 8;
    return x ^ ans;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        for(int x = 0; x <= 255; x++)
            if(calc(x) == a){
                cout << x << " ";
                break;
            }
    }
}