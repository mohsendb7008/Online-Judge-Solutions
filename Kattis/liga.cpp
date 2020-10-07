#include <bits/stdc++.h>
using namespace std;

// Liga

int su, w, d, l, ps;

int read(){
    string s;
    cin >> s;
    if(s == "?")
        return -1;
    return stoi(s);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        su = read(), w = read(), d = read(), l = read(), ps = read();
        if(su == -1 && l == -1)
            l = 0;
        int w1 = (w == -1) ? 0 : w, w2 = (w == -1) ? 100 : w;
        int d1 = (d == -1) ? 0 : d, d2 = (d == -1) ? 100 : d;
        for(int cw = w1; cw <= w2; cw++)
            for(int cd = d1; cd <= d2; cd++){
                int cps = 3 * cw + cd;
                if(ps != -1 && ps != cps)
                    continue;
                int csu, cl;
                if(l != -1){
                    cl = l;
                    csu = cw + cd + cl;
                    if(su != -1 && su != csu)
                        continue;
                }
                else{
                    csu = su;
                    cl = csu - cw - cd;
                    if(l != -1 && l != cl)
                        continue;
                }
                if(csu > 100)
                    continue;
                su = csu, w = cw, d = cd, l = cl, ps = cps;
                break;
            }
        cout << su << " " << w << " " << d << " " << l << " " << ps << endl;
    }
}