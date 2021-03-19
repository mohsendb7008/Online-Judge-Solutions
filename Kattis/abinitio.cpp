#include<bits/stdc++.h>
using namespace std;

// Ab Initio

#define long long long int

const int maxn = 4003;

const long mod = 1e9 + 7;

int n, m, q;
bool transpose = false, complement = false, matrix[maxn][maxn];

int main(){
    scanf("%d %d %d", &n, &m, &q);
    while(m--){
        int u, v;
        scanf("%d %d", &u, &v);
        matrix[u][v] = true;
    }
    while(q--){
        int c, x, y;
        scanf("%d", &c);
        if(c == 1){
            if(complement){
                for(int i = 0; i < n; i++)
                    matrix[i][n] = matrix[n][i] = true;
            }
            n++;
        }
        else if(c == 2){
            scanf("%d %d", &x, &y);
            if(transpose)
                swap(x, y);
            matrix[x][y] = !complement;
        }
        else if(c == 3){
            scanf("%d", &x);
            for(int i = 0; i < n; i++)
                if(i != x)
                    matrix[i][x] = matrix[x][i] = complement;
        }
        else if(c == 4){
            scanf("%d %d", &x, &y);
            if(transpose)
                swap(x, y);
            matrix[x][y] = complement;
        }
        else if(c == 5)
            transpose = !transpose;
        else if(c == 6)
            complement = !complement;
    }
    printf("%d\n", n);
    for(int i = 0; i < n; i++){
        int cnt = 0;
        long h = 0, seven = 1;
        for(int j = 0; j < n; j++){
            if(j == i)
                continue;
            int x = i, y = j;
            if(transpose)
                swap(x, y);
            if(complement ^ matrix[x][y]){
                cnt++;
                h = (h + (seven * j) % mod) % mod;
                seven = (seven * 7) % mod;
            }
        }
        printf("%d %lld\n", cnt, h);
    }
}
