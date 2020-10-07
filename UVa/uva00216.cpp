#include <bits/stdc++.h>
using namespace std;

// Getting in Line

int n;
pair<double, double> points[11];

double distance(pair<double, double> p1, pair<double, double> p2){
    double deltax = p1.first - p2.first;
    double deltay = p1.second - p2.second;
    return sqrt(deltax * deltax + deltay * deltay);
}

double w[11][11];
double tsp[259][11];
int trace[259][11];

double csp(int mask, int u){
    if(tsp[mask][u] != -1)
        return tsp[mask][u];
    if(mask == 0)
        return tsp[mask][u] = 0;
    double ans = INT_MAX;
    for(int v = 0; v < n; v++){
        if(v == u || !(mask & (1 << v)))
            continue;
        double value = csp(mask & (~(1 << v)), v) + w[v][u];
        if(value < ans){
            ans = value;
            trace[mask][u] = v;
        }
    }
    return tsp[mask][u] = ans;
}

int path[11];

int main(){
    int test = 1;
    while(true){
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
            cin >> points[i].first >> points[i].second;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                w[i][j] = distance(points[i], points[j]);
        for(int i = 0; i < 259; i++)
            for(int j = 0; j < 11; j++){
                tsp[i][j] = -1;
                trace[i][j] = -1;
            }
        double ans = INT_MAX;
        int it = -1;
        int mask = pow(2, n) - 1;
        for(int u = 0; u < n; u++){
            double value = csp(mask - (1 << u), u);
            if(value < ans){
                ans = value;
                it = u;
            }
        }
        int cnt = 0;
        while(it != -1){
            path[cnt++] = it;
            mask = mask - (1 << it);
            it = trace[mask][it];
        }
        for(int i = 0; i < 58; i++)
            printf("*");
        printf("\nNetwork #%d\n", test++);
        ans = 0;
        for(int i = 0; i < n-1; i++){
            pair<int, int> a = points[path[i]];
            pair<int, int> b = points[path[i+1]];
            double d = distance(a, b) + 16;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", a.first, a.second, b.first, b.second, d);
            ans += d;
        }
        printf("Number of feet of cable required is %.2f.\n", ans);
    }
}