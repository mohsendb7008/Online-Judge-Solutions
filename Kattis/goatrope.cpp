#include <bits/stdc++.h>
using namespace std;

// Goat Rope

struct point{
    double x, y;
    
    point(){
        x = 0, y = 0;
    }
    
    point(double x, double y){
        this->x = x, this->y = y;
    }

    double dist(const point& o){
        return hypot(x - o.x, y - o.y);
    }
};

struct vec{
    double x, y;
    
    vec(double x, double y){
        this->x = x;
        this->y = y;
    }

    vec(point & p1, point & p2){
        this->x = p2.x - p1.x;
        this->y = p2.y - p1.y;
    }

    vec scale(double s){
        return vec(this->x * s, this->y * s);
    }

    point translate(point & p){
        return point(p.x + this->x, p.y + this->y);
    }

    double dot(vec & o){
        return this->x * o.x + this->y * o.y;
    }

    double norm_squared(){
        return this->x * this->x + this->y * this->y;
    }
};

double dist_to_line_segment(point & p, point & a, point & b){
    vec ap = vec(a, p);
    vec ab = vec(a, b);
    double u = ab.dot(ap) / ab.norm_squared();
    if(u < 0)
        return p.dist(a);
    if(u > 1)
        return p.dist(b);
    return ab.scale(u).translate(a).dist(p);;
}

double x, y, x11, y11, x22, y22;

int main(){
    cin >> x >> y >> x11 >> y11 >> x22 >> y22;
    point p(x, y), a(x11, y11), b(x11, y22), c(x22, y11), d(x22, y22);
    double ans = dist_to_line_segment(p, a, b);
    ans = min(ans, dist_to_line_segment(p, a, c));
    ans = min(ans, dist_to_line_segment(p, c, d));
    ans = min(ans, dist_to_line_segment(p, b, d));
    cout << fixed << setprecision(5) << ans << endl;
}