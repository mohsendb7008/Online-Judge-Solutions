#include <bits/stdc++.h>
using namespace std;

// Bus Numbers

const int maxn = 1e8 + 3;

int ways[maxn];

int main(){
    for(int i = 1; i <= 350; i++)
        for(int j = i; j <= 350; j++)
            ways[i * i * i + j * j * j]++;
    int m;
    cin >> m;
    while(m && ways[m] < 2)
        m--;
    if(m)
        cout << m << endl;
    else
        cout << "none" << endl;
}