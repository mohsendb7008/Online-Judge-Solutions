#include <bits/stdc++.h>
using namespace std;

// Packets

int one, two, three, four, five, six;

int main(){
    while(1){
        cin >> one >> two >> three >> four >> five >> six;
        if(one + two + three + four + five + six == 0)
            break;
        int ans = six, left;
        ans += five;
        one -= min(one, five * 11);
        ans += four;
        left = 5 * four;
        one -= min(one, max(0, left - two) * 4);
        two -= min(two, left);
        ans += three / 4;
        three %= 4;
        if(three == 1){
            ans++;
            one -= min(one, 7 + max(0, 5 - two) * 4);
            two -= min(two, 5);
        }
        else if(three == 2){
            ans++;
            one -= min(one, 6 + max(0, 3 - two) * 4);
            two -= min(two, 3);
        }
        else if(three == 3){
            ans++;
            one -= min(one, 5 + max(0, 1 - two) * 4);
            two -= min(two, 1);
        }
        
        ans += two / 9;
        two %= 9;
        if(two){
            ans++;
            one -= min(one, (9 - two) * 4);
        }
        ans += one / 36 + (one % 36 ? 1 : 0);
        cout << ans << endl;
    }
}
