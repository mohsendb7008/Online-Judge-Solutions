#include <bits/stdc++.h>
using namespace std;

// Ptice

char a[4] = "ABC", b[5] = "BABC", c[7] = "CCAABB";
int N;
char correct[103];

int main(){
    cin >> N >> correct;
    int a1 = 0, b1 = 0, c1 = 0;
    for(int i = 0; i < N; i++){
        if(correct[i] == a[i%3])
            a1++;
        if(correct[i] == b[i%4])
            b1++;
        if(correct[i] == c[i%6])
            c1++;
    }
    int M = max(a1, max(b1, c1));
    cout << M << endl;
    if(a1 == M)
        cout << "Adrian" << endl;
    if(b1 == M)
        cout << "Bruno" << endl;
    if(c1 == M)
        cout << "Goran" << endl;
}