#include <bits/stdc++.h>
using namespace std;

// Hurricane Danger!

#define EPS 1e-9

struct point{
    double x, y;
    
    point() = default;
    
    point(double x, double y){
        this->x = x, this->y = y;
    }

    double dist(const point& o){
        return hypot(x - o.x, y - o.y);
    }
};

struct vec{
    double x, y;
    
	vec() = default;
	
    vec(double x, double y){
        this->x = x;
        this->y = y;
    }

    vec(point& p1, point& p2){
        this->x = p2.x - p1.x;
        this->y = p2.y - p1.y;
    }

    vec scale(double s){
        return vec(this->x * s, this->y * s);
    }

    point translate(point& p){
        return point(p.x + this->x, p.y + this->y);
    }

    double dot(vec& o){
        return this->x * o.x + this->y * o.y;
    }

    double norm_squared(){
        return this->x * this->x + this->y * this->y;
    }
};

double dist_to_line(point& p, point& a, point& b){
    vec ap = vec(a, p);
    vec ab = vec(a, b);
    double u = ab.dot(ap) / ab.norm_squared();
    return ab.scale(u).translate(a).dist(p);
}

point a, b;
int n;
string names[103];
point cities[103];
double d[103];

int main(){
    int m;
    cin >> m;
    while(m--){
        cin >> a.x >> a.y >> b.x >> b.y;
        double ans = LLONG_MAX;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> names[i] >> cities[i].x >> cities[i].y;
            d[i] = dist_to_line(cities[i], a, b), ans = min(ans, d[i]);
        }
        for(int i = 0; i < n; i++)
            if(fabs(d[i] - ans) < EPS)
                cout << names[i] << " ";
        cout << endl;
    }
}