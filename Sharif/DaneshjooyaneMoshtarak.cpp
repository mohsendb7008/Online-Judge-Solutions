#include <bits/stdc++.h>
using namespace std;

int n, k, q, mat[203][503];
vector<int> classes;

int main(){
    scanf("%d %d %d", &n, &k, &q);
    int d, j;
    for(int i = 0; i < k; i++){
        scanf("%d", &d);
        while(d--)
            scanf("%d", &j), mat[j - 1][i] = 1;
    }
    while(q--){
        classes.clear();
        scanf("%d", &d);
        while(d--)
            scanf("%d", &j), classes.push_back(j - 1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            bool ok = 1;
            for(int j : classes)
                if(!mat[i][j]){
                    ok = 0;
                    break;
                }
            ans += ok;
        }
        printf("%d\n", ans);
    }
}