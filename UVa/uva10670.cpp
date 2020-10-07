#include <bits/stdc++.h>
using namespace std;

// Work Reduction

struct agency{
    string name;
    int ans;
};

bool cmp(const agency& a1, const agency& a2){
    if(a1.ans == a2.ans)
        return a1.name < a2.name;
    return a1.ans < a2.ans;
}

int solve(int n, int m, int a, int b){
    if(n / 2 < m)
        return (n - m) * a;
    return min(b, a * (n - n/2)) + solve(n/2, m, a, b);    
}

agency agencies[103];

int main(){
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++){
        int n, m, l;
        cin >> n >> m >> l;
        for(int i = 0; i < l; i++){
            char tmp[20];
            int a, b;
            scanf("\n%[^:]:%d,%d", tmp, &a, &b);
            agencies[i].name = string(tmp);
            agencies[i].ans = solve(n, m, a, b);
        }
        sort(agencies, agencies+l, cmp);
        cout << "Case " << c << endl;
        for(int i = 0; i < l; i++)
            cout << agencies[i].name << " " << agencies[i].ans << endl; 
    }
}