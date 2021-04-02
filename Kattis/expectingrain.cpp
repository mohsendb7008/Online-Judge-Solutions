#include <bits/stdc++.h>
using namespace std;

// Expecting Rain

int d, T, c, r;
struct cloud{
    int s, e;
    double p, a;
    bool operator<(const cloud& o) const{
        return this->e > o.e;
    }
} clouds[1000003];
bool cmp(const cloud& c1, const cloud& c2){
    return c1.s < c2.s;
}
priority_queue<cloud> pq;
double rainingValue[10003];
pair<int, int> roofs[1003];
bool isRoof[1003];
double dp[1003][10003];

int main(){
    scanf("%d %d %d %d", &d, &T, &c, &r);
    for(int i = 0; i < c; i++)
        scanf("%d %d %lf %lf", &clouds[i].s, &clouds[i].e, &clouds[i].p, &clouds[i].a), clouds[i].e--;
    for(int i = 0; i < r; i++)
        scanf("%d %d", &roofs[i].first, &roofs[i].second), roofs[i].second--;
    sort(clouds, clouds + c, cmp);
    double rvalue = 0.0;
    int ptr = 0;
    for(int s = 0; s <= T; s++){
        while(ptr < c && clouds[ptr].s <= s)
            rvalue += clouds[ptr].p * clouds[ptr].a, pq.push(clouds[ptr++]);
        while(!pq.empty() && pq.top().e < s)
            rvalue -= pq.top().p * pq.top().a, pq.pop();
        rainingValue[s] = rvalue;
    }
    sort(roofs, roofs + r);
    for(int i = 0; i < r; i++)
        for(int x = roofs[i].first; x <= roofs[i].second; x++)
            isRoof[x] = true;
    for(int t = T; t >= 0; t--)
        for(int x = d; x >= 0; x--){
            if(d - x > T - t)
                continue;
            if(t == T)
                dp[x][t] = 0;
            else if(x == d)
                dp[x][t] = isRoof[x] ? 0 : rainingValue[t] +  dp[x][t + 1];
            else if(x == 0){
                dp[x][t] = (isRoof[x] ? 0 : rainingValue[t]) + dp[x + 1][t + 1];
                if(d - x < T - t)
                    dp[x][t] = min(dp[x][t], dp[x][t + 1]);   
            }
            else{ 
                dp[x][t] = isRoof[x] ? 0 : rainingValue[t]; 
                double subp = dp[x + 1][t + 1];
                if(d - x < T - t)
                    subp = min(subp, dp[x][t + 1]);
                dp[x][t] += subp;
            }
        }
    printf("%.5f", dp[0][0]);
}