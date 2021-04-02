#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 3e5 + 3;

int n, q, ptr[maxn];
vector<num> psum;

int main(){
    scanf("%d %d", &n, &q);
    while(q--){
        int c, x, i, j;
        scanf("%d", &c);
        if(c == 1){
            scanf("%d", &x);
            psum.push_back(x + (psum.empty() ? 0 : psum.back()));
        }
        else if(c == 2){
            scanf("%d %d", &i, &j), i--;
            if(!j)
                printf("0\n");
            else{
                printf("%lld\n", psum[ptr[i] + j - 1] - (ptr[i] ? psum[ptr[i] - 1] : 0));
                ptr[i] += j;
            }
        }
    }
}