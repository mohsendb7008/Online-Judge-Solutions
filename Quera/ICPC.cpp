#include <bits/stdc++.h>
using namespace std;

int s1, s2, p1, p2;

int main(){
    cin >> p1 >> s1 >> s2 >> p2;
    if(p1 + p2 > s1 + s2)
        cout << "Persepolis" << endl;
    else if(p1 + p2 < s1 + s2)
        cout << "Esteghlal" << endl;
    else if(s1 > p2)
        cout << "Esteghlal" << endl;
    else if(s1 < p2)
        cout << "Persepolis" << endl;
    else
        cout << "Penalty" << endl;
}