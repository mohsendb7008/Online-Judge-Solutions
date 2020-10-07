#include <bits/stdc++.h>
using namespace std;

// Track Smoothing

#define EPS 1e-9

struct point{
    double x, y;
    
    point() = default;
    
    point(double x, double y){
        this->x = x, this->y = y;
    }
	
	point& operator=(const point& o) = default; 
    
    double dist(const point& o){
        return hypot(x - o.x, y - o.y);
    }
};

double r;
int n;
point polygon[10003];

int main(){
    int t;
    cin >> t;
    cout << fixed << setprecision(6);
    while(t--){
        cin >> r >> n;
        for(int i = 0; i < n; i++)
            cin >> polygon[i].x >> polygon[i].y;
        double P = 0;
        for(int i = 0; i < n; i++)
            P += polygon[i].dist(polygon[(i + 1) % n]);
        if(P - 2 * M_PI * r > -EPS)
            cout << (P - 2 * M_PI * r) / P << endl;
        else
            cout << "Not possible" << endl;
    }
}