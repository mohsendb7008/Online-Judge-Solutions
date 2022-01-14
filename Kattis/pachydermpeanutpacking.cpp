// Pachyderm Peanut Packing

#include <bits/stdc++.h>
using namespace std;

int n, m;
double x1[33], x2[33], y11[33], y2[33];
string type[33];

int main(){
    while(1){
        cin >> n;
        if(!n){
            break;
        }
        for(int i = 0; i < n; i++){
            cin >> x1[i] >> y11[i] >> x2[i] >> y2[i] >> type[i];
        }
        cin >> m;
        while(m--){
            double x, y;
            string t;
            cin >> x >> y >> t;
            string where = "floor";
            for(int i = 0; i < n; i++){
                if(x >= x1[i] && x <= x2[i] && y >= y11[i] && y <= y2[i]){
                    where = type[i];
                    break;
                }
            }
            if(where == t){
                where = "correct";
            }
            cout << t << " " << where << endl;
        }
        cout << endl;
    }
}