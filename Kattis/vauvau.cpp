#include <bits/stdc++.h>
using namespace std;

// Vauvau

int A, B, C, D, P, M, G;

string solve(int minute){
    int cnt = 0;
    if(minute % (A + B) < A)
        cnt++;
    if(minute % (C + D) < C)
        cnt++;
    if(cnt == 2)
        return "both";
    if(cnt == 1)
        return "one";
    return "none";
}

int main(){
    cin >> A >> B >> C >> D >> P >> M >> G;
    cout << solve(P - 1) << endl;
    cout << solve(M - 1) << endl;
    cout << solve(G - 1) << endl;
}