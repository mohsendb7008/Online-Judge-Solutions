#include <bits/stdc++.h>
using namespace std;

// Dropping Balls

int main(){
    int t;
    cin >> t;
    while(t--){
        int d, i;
        cin >> d >> i;
        i--;
        int path = 1;
        for(int j = 0; j < d-1; j++){
            if(i % 2 == 0)
                path *= 2;
            else path = path*2 + 1;
            i /= 2;
        }
        cout << path << endl;
    }
    cin >> t;
}