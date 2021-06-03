#include <bits/stdc++.h>
using namespace std;

// Mjehuric

int a[5];

int main(){
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    while(1){
        for(int i = 0; i < 4; i++)
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                for(int i = 0; i < 5; i++)
                    cout << a[i] << " \n"[i==4];
            }
        if(a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5)
            break;
    }
}