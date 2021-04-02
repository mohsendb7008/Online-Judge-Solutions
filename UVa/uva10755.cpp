#include <bits/stdc++.h>
using namespace std;

// Garbage Heap

#define num long long int

num a[23][23][23];
num psum[23][23][23];
int A, B, C;

num get(int i, int j, int k){
    if(i >= 0 && i < A && j >= 0 && j < B && k >= 0 && k < C)
        return psum[i][j][k];
    return 0;
}

void build(){
    for(int i = 0; i < A; i++)
        for(int j = 0; j < B; j++)
            for(int k = 0; k < C; k++)
                psum[i][j][k] = a[i][j][k] + get(i-1, j, k) + get(i, j-1, k) + get(i, j, k-1) - get(i-1, j-1, k) - get(i-1, j, k-1) - get(i, j-1, k-1) + get(i-1, j-1, k-1);
}

num dp_value(int i1, int j1, int k1, int i2, int j2, int k2){
    return get(i2, j2, k2) - get(i1-1, j2, k2) - get(i2, j1-1, k2) - get(i2, j2, k1-1) + get(i1-1, j1-1, k2) + get(i1-1, j2, k1-1) + get(i2, j1-1, k1-1) - get(i1-1, j1-1, k1-1);
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> A >> B >> C;
        for(int i = 0; i < A; i++)
            for(int j = 0; j < B; j++)
                for(int k = 0; k < C; k++)
                    cin >> a[i][j][k];

        build();

        num ans = dp_value(0, 0, 0, 0, 0, 0);
        for(int i1 = 0; i1 < A; i1++)
            for(int j1 = 0; j1 < B; j1++)
                for(int k1 = 0; k1 < C; k1++)
                    for(int i2 = i1; i2 < A; i2++)
                        for(int j2 = j1; j2 < B; j2++)
                            for(int k2 = k1; k2 < C; k2++)
                               ans = max(ans, dp_value(i1, j1, k1, i2, j2, k2));
        cout << ans << endl;
        if(test != 0)
            cout << endl;
    }

}