#include <bits/stdc++.h>
using namespace std;

// Expeditious Cubing

vector<int> t;
int x, d, tf, ans;

int main(){
    for(int i = 0; i < 4; i++){
        scanf("%d.%d", &x, &d);
        t.push_back(100 * x + d);
    }
    scanf("%d.%d", &x, &d);
    tf = 100 * x + d;
    sort(t.begin(), t.end());
    if(t[1] + t[2] + t[3] <= 3 * tf)
        printf("infinite\n");
    else if(t[0] + t[1] + t[2] > 3 * tf)
        printf("impossible\n");
    else{
        ans = 3 * tf - t[2] - t[1];
        printf("%d.%02d\n", ans / 100, ans % 100);
    }
}