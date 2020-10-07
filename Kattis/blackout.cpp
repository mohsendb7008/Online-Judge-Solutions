#include <bits/stdc++.h>
using namespace std;

// Black Out

int main(){
    int n;
    cin >> n;
    while(n--){
        cout << "3 1 3 6" << endl;
        cout.flush();
        string cmd;
        int r1, c1, r2, c2;
        while(1){
            cin >> cmd;
            if(cmd == "GAME")
                break;
            cin >> r1 >> c1 >> r2 >> c2;
            if(r1 == r2)
                cout << 6 - r1 << " " << min(7 - c1, 7 - c2) << " " << 6 - r1 << " " << max(7 - c1, 7 - c2) << endl;
            else 
                cout << min(6 - r1, 6 - r2) << " " << 7 - c1 << " " << max(6 - r1, 6 - r2) << " " << 7 - c1 << endl;
            cout.flush();
        }
    }
}