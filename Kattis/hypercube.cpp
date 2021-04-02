#include <bits/stdc++.h>
using namespace std;

// Hamiltonian Hypercube

int n;
long long int p[63];
string s1, s2;

long long int ind(string s){
    long long int j = 0;
    bool r = false;
    for(int i = 0; i < n; i++){
        if((s[i] == '1') != r)
            j += p[n-i-1];
        if(s[i] == '1')
            r = !r;
    }
    return j;
}

int main(){
    cin >> n >> s1 >> s2;
    p[0] = 1;
    for(int i = 1; i <= n; i++)
        p[i] = p[i-1] * 2;
    long long int a = ind(s1), b = ind(s2);
    cout << max(0ll, max(a, b) - min(a, b) - 1)  << endl;
}