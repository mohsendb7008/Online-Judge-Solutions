#include <bits/stdc++.h>
using namespace std;

// Hard Drive

int n, c, b;
bool ans[500003], broken[500003];

int main(){
    cin >> n >> c >> b;
    int x;
    while(b--)
        cin >> x, broken[x-1] = true;
    x = n-1;
    while(c){
        if(c == 1){
            ans[0] = 1;
            break;
        }
        if(broken[x])
            x--;
        else
            ans[x] = 1, c -= 2, x -= 2;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;   
}