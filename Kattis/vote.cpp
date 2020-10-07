#include <bits/stdc++.h>
using namespace std;

// Popular Vote

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, sum = 0, mvote = -1, ind;
        bool ok = true;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> x, sum += x;
            if(x > mvote)
                mvote = x, ind = i, ok = true;
            else if(x == mvote)
                ok = false;
        }
        if(mvote == -1 || !ok)
            cout << "no winner" << endl;
        else cout << (mvote > sum / 2 ? "majority winner " : "minority winner ") << ind << endl; 
    } 
}