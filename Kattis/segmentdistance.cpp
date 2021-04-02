#include <bits/stdc++.h>
using namespace std;

// Line Segment Distance

#define EPS 1e-8

struct point{
    double x, y;
    
    point() = default;
    
    point(double x, double y){
        this->x = x, this->y = y;
    }
    
    bool operator==(const point& o) const{
        return fabs(x - o.x) < EPS && fabs(y - o.y) < EPS;
    }

    double dist(const point& o){
        return hypot(x - o.x, y - o.y);
    }
};

#define INF LLONG_MAX

struct line{
    double m, b;
	
	line() = default;
    
    line(point& p1, point& p2){
        if(fabs(p1.x - p2.x) < EPS)
            m = INF, b = p1.x;
        else if(fabs(p1.y - p2.y) < EPS)
            m = 0, b = p1.y;
        else{
            m = (p1.y - p2.y) / (p1.x - p2.x);
            b = p1.y - m * p1.x;
        }
    }

    bool parallel(const line& o) const{
        return fabs(this->m - o.m) < EPS;
    }

    point intersect(const line& o) const{
        if(this->m == INF)
            return point(this->b, o.m * this->b + o.b);
        if(o.m == INF)
            return point(o.b, this->m * o.b + this->b);
        double x = (o.b - this->b) / (this->m - o.m);
        return point(x, this->m * x + this->b);
    }
};

bool on_line_segment(point& a, point& b, point& c){
    return fabs(a.dist(b) - c.dist(a) - c.dist(b)) < EPS;
}

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

double dist_to_line_segment(point& p, point& a, point& b){
    vec ap = vec(a, p);
    vec ab = vec(a, b);
    double u = ab.dot(ap) / ab.norm_squared();
    if(u < 0)
        return p.dist(a);
    if(u > 1)
        return p.dist(b);
    return dist_to_line(p, a, b);
}

double dist_of_line_segments(point& p1, point& p2, point& q1, point& q2){
    line l1(p1, p2), l2(q1, q2);
    if(!l1.parallel(l2)){
        point inter = l1.intersect(l2);
        if(on_line_segment(p1, p2, inter) && on_line_segment(q1, q2, inter))
            return 0.0;
    }
    double ans1 = min(dist_to_line_segment(q1, p1, p2), dist_to_line_segment(q2, p1, p2));
    if(p1 == p2)
        ans1 = min(p1.dist(q1), p1.dist(q2));
    double ans2 = min(dist_to_line_segment(p1, q1, q2), dist_to_line_segment(p2, q1, q2));
    if(q1 == q2)
        ans2 = min(q1.dist(p1), q1.dist(p2));
    return min(ans1, ans2);
}

int n;
point p1, p2, q1, q2;

int main(){
    cout << fixed << setprecision(2);
    cin >> n;
    while(n--){
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> q1.x >> q1.y >> q2.x >> q2.y;
        cout << dist_of_line_segments(p1, p2, q1, q2) << endl;
    }
}