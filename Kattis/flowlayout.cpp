// Flow Layout

#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int w;
        cin >> w;
        if(!w){
            break;
        }
        int cur_w = 0;
        int max_h = 0;
        int tot_w = 0;
        int tot_h = 0;
        while(1){
            int x, y;
            cin >> x >> y;
            if(x + y == -2){
                cout << tot_w << " x " << tot_h + max_h << endl;
                break;
            }
            if(cur_w + x > w){
                cur_w = 0;
                tot_h += max_h;
                max_h = 0;   
            }
            cur_w += x;
            tot_w = max(tot_w, cur_w);
            max_h = max(max_h, y);
        }
    }
}