#include <bits/stdc++.h>
using namespace std;

// Odds of Mia

map<string, int> mia{
    {"21", 1}, {"66", 2}, {"55", 3},
    {"44", 4}, {"33", 5}, {"22", 6},
    {"11", 7}, {"65", 8}, {"64", 9},
    {"63", 10}, {"62", 11}, {"61", 12},
    {"54", 13}, {"53", 14}, {"52", 15},
    {"51", 16}, {"43", 17}, {"42", 18},
    {"41", 19}, {"32", 20}, {"31", 21}
};

int gcd(int a, int b){
    if(!a)
        return b;
    return gcd(b % a, a);
}

char a, b, c, d;

int main(){
    while(1){
        cin >> a >> b >> c >> d;
        if(a == '0' && b == '0' && c == '0' && d == '0')
            break;
        int win = 0, all = 0;
        for(char a1 = '1'; a1 <= '6'; a1++)
            if(a == '*' || a1 == a)
                for(char b1 = '1'; b1 <= '6'; b1++)
                    if(b == '*' || b1 == b)
                        for(char c1 = '1'; c1 <= '6'; c1++)
                            if(c == '*' || c1 == c)
                                for(char d1 = '1'; d1 <= '6'; d1++)
                                    if(d == '*' || d1 == d){
                                        all++;
                                        string first = "", second = "";
                                        first += max(a1, b1), first += min(a1, b1);
                                        second += max(c1, d1), second += min(c1, d1);
                                        if(mia[first] < mia[second])
                                            win++;
                                    }
        if(!win)
            cout << 0 << endl;
        else if(win == all)
            cout << 1 << endl;
        else{
            int g = gcd(win, all);
            cout << (win / g) << "/" << (all / g) << endl;
        }
    }
}