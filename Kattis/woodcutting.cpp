#include <bits/stdc++.h>
using namespace std;

// Wood Cutting

#define num long long int

int n;
num wood[100003];

int main(){
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            num w, x;
            cin >> w;
            wood[i] = 0;
            while(w--){
                cin >> x;
                wood[i] += x;
            }
        }
        sort(wood, wood+n);
        num ans = 0;
        for(int i = 0; i < n; i++)
            ans += wood[i] * (n - i);
        cout << double(ans) / n << endl;
    }
}