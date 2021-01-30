#include <bits/stdc++.h>
using namespace std;

// Jack and the Beanbag

int beans, required[20], farmers, farmer_beans[100], sum[1 << 20];

int main(){
    cin >> beans;
    for(int i = 0; i < beans; i++)
        cin >> required[i];
    cin >> farmers;
    for(int i = 0; i < farmers; i++){
        int length, bean;
        cin >> length;
        while(length--)
            cin >> bean, farmer_beans[i] += 1 << (bean - 1);
    }
    for(int mask = 1; mask < (1 << beans); mask++)
        for(int bean = 0; bean < beans; bean++)
            if(mask & (1 << bean)){
                sum[mask] = sum[mask - (1 << bean)] + required[bean];
                break;
            }
    int ans = 0;
    for(int mask = 1; mask < (1 << beans); mask++){
        bool feasible = true;
        for(int farmer = 0; farmer < farmers; farmer++)
            if(!(farmer_beans[farmer] & mask)){
                feasible = false;
                break;
            }
        if(feasible)
            ans = max(ans, sum[(1 << beans) - 1 - mask]);
    }
    cout << ans << endl;
}