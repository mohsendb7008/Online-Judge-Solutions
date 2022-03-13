// Growling Gears

#include <bits/stdc++.h>
using namespace std;

int n, a[13], b[13], c[13];

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        double r0 = double(b[0]) / (2 * a[0]);
        double max_ans = -a[0] * r0 * r0 + b[0] * r0 + c[0];
        int max_ans_index = 0;
        for(int i = 1; i < n; i++){
            double r = double(b[i]) / (2 * a[i]);
            double ans = - a[i] * r * r + b[i] * r + c[i];
            if(ans > max_ans){
                max_ans = ans;
                max_ans_index = i;
            }
        }
        cout << max_ans_index + 1 << endl;
    }
}