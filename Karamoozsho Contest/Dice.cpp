#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int p = 5, q = 2, u = 4, v = 3, m = 6, n = 1;
    string s;
    cin >> s;
    for(char c: s){
        int p1 = p, q1 = q, u1 = u, v1 = v, m1 = m, n1 = n;
        if(c == 'a'){
            p = n1, q = m1, u = u1, v = v1, m = p1, n = q1;
        }else if(c == 'b'){
            p = m1, q = n1, u = u1, v = v1, m = q1, n = p1;
        }else if(c == 'c'){
            p = u1, q = v1, u = q1, v = p1, m = m1, n = n1;
        }else if(c == 'd'){
            p = v1, q = u1, u = p1, v = q1, m = m1, n = n1;
        }else if(c == 'e'){
            p = p1, q = q1, u = n1, v = m1, m = u1, n = v1;
        }else if(c == 'f'){
            p = p1, q = q1, u = m1, v = n1, m = v1, n = u1;
        }
    }
    cout << p << endl;
    return 0;
}