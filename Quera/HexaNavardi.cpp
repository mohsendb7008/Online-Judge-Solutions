#include <bits/stdc++.h>
using namespace std;

void move(char c, int& x, int& y){
    if(c == 'A')
        x--, y++;
    else if(c == 'B')
        x++, y++;
    else if(c == 'C')
        x += 2;
    else if(c == 'D')
        x++, y--;
    else if(c == 'E')
        x--, y--;
    else if(c == 'F')
        x -= 2;
}

int main(){
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        int x = 0, y = 0;
        for(char c : s)
            move(c, x, y);
        int a = 0, b = 0, ans = 0;
        while(b != y){
            if(b < y){
                if(a <= x)
                    move('B', a, b);
                else
                    move('A', a, b);
            }
            else if(b > y){
                if(a <= x)
                    move('D', a, b);
                else
                    move('E', a, b);
            }
            ans++;
        }
        ans += abs(a - x) / 2;
        cout << ans << endl;
    }
}