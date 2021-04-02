 #include<bits/stdc++.h>
using namespace std;

#define num long long int

bitset<1000001> pf;
int spf[1000001];

map<int, int> factors;

inline void factorize(int x){
    factors.clear();
    while(x > 1)
        factors[spf[x]]++, x /= spf[x];
}

int n, a;
map<int, int> comp;

int main(){
    pf.set();
    for(num p = 2; p < 1000001; p++){
        if(pf[p]){
            spf[p] = p;
            for(num q = p * p; q < 1000001; q += p)
                if(pf[q])
                    pf[q] = 0, spf[q] = p;
        }
    }
    int t;
    scanf("%d", &t);
    while(t--){
        comp.clear();
        scanf("%d", &n);
        while(n--){
            scanf("%d", &a);
            factorize(a);
            int leader = 1;
            for(auto it : factors)
                if(it.second % 2)
                    leader *= it.first;
            comp[leader]++;
        }
        int ans1 = 0, ans2 = comp[1];
        for(auto it : comp)
            ans1 = max(ans1, it.second);
        for(auto it : comp)
            if(it.first != 1 && !(it.second % 2))
                ans2 += it.second;
        for(auto it : comp)
            if(it.first != 1 && it.second % 2)
                ans2 = max(ans2, it.second);
        int q;
        num w;
        scanf("%d", &q);
        while(q--){
            scanf("%lld", &w);
            if(w)
                printf("%d\n", ans2);
            else
                printf("%d\n", ans1);
        }
    }
}