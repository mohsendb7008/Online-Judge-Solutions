#include <bits/stdc++.h>
using namespace std;

// Musical Chairs

int n, ch[10003], ind[10003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ch[i], ind[i] = i + 1;
    int ptr = 0;
    while(n > 1){
        ptr = (ptr + ch[ptr] - 1) % n;
        for(int i = ptr; i < n-1; i++)
            ch[i] = ch[i+1], ind[i] = ind[i+1];
        n--;
        ptr %= n;
    }
    cout << ind[0] << endl;
}