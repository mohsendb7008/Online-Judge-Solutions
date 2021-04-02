#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n, c, a[maxn];
vector<int> tmp;
set<int> seen;
stack<int> st;

void solve(){
    int it = 1;
    while(c--){
        int x;
        scanf("%d", &x);
        if(x)
            st.push(x);
        else{
            if(st.empty()){
                while(seen.find(it) != seen.end())
                    it++;
                printf("%d\n", it++);
            }
            else{
                printf("%d\n", st.top());
                seen.insert(st.top());
                st.pop();
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &c);
    if(c < n){
        solve();
        return 0;
    }
    iota(a, a+n, 1);
    while(c--){
        int x;
        scanf("%d", &x);
        if(x){
            tmp.clear();
            tmp.push_back(x);
            for(int i = 0; i < n; i++)
                if(a[i] != x)
                    tmp.push_back(a[i]);
            for(int i = 0; i < n; i++)
                a[i] = tmp[i];
        }else{
            printf("%d\n", a[0]);
            int tmp = a[0];
            for(int i = 0; i < n-1; i++)
                a[i] = a[i+1];
            a[n-1] = tmp;
        }
    }
}