#include <bits/stdc++.h>
using namespace std;

// Murica's Skyline

int n;
int h[10003], w[10003];
int lis[10003], lds[10003];

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> h[i];
        for(int i = 0; i < n; i++)
            cin >> w[i];
        for(int i = n-1; i >= 0; i--){
            lis[i] = w[i];
            lds[i] = w[i];
            for(int j = i + 1; j < n; j++){
                if(h[j] > h[i])
                    lis[i] = max(lis[i], lis[j] + w[i]);
                if(h[j] < h[i])
                    lds[i] = max(lds[i], lds[j] + w[i]);
            }
        }
        int a = *max_element(lis, lis+n);
        int b = *max_element(lds, lds+n);
        if(a >= b)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, a, b);
        else 
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, b, a);
    }
}