#include <bits/stdc++.h>
using namespace std;

int cnt = 1;

void hanoi(int n, char A, char B, char C){
    if(n == 1){
        cout << cnt++ << ' ' << A << ' ' << C << '\n';
        return;
    }
    hanoi(n-1, A, C, B);
    cout << cnt++ << ' ' << A << ' ' << C << '\n';
    hanoi(n-1, B, A, C);
}

int main(){
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
}