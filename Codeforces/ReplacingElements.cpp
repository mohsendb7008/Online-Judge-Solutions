#include <bits/stdc++.h>
using namespace std;

int n, d, a[103];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        bool flat = 1;
        for(int i = 0; i < n; i++)
            if(a[i] > d){
                flat = 0;
                break;
            }
        if(flat){
            cout << "YES" << endl;
            continue;
        }
        bool ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++)
                if(a[i] + a[j] <= d){
                    ans = 1;
                    break;
                }
            if(ans)
                break;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}
