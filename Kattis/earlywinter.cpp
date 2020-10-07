#include <bits/stdc++.h>
using namespace std;

// Early Winter

int n, d;

int main(){
    cin >> n >> d;
    int ans = -1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x <= d){
            ans = i;
            break;
        }
    }

    if(ans == -1)
        printf("It had never snowed this early!\n");
    else
        printf("It hadn't snowed this early in %d years!\n", ans);
}