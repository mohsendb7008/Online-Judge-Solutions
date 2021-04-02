#include <bits/stdc++.h>
using namespace std;

// Counting Triangles

#define EPS 1e-9
#define INF LLONG_MAX

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

struct line{
    double m, b;

    line() = default;
    
    line(point & p1, point & p2){
        if(fabs(p1.x - p2.x) < EPS)
            m = INF, b = p1.x;
        else if(fabs(p1.y - p2.y) < EPS)
            m = 0, b = p1.y;
        else{
            m = (p1.y - p2.y) / (p1.x - p2.x);
            b = p1.y - m * p1.x;
        }
    }

    bool parallel(const line & o) const{
        return fabs(this->m - o.m) < EPS;
    }

    point intersect(const line & o) const{
        if(this->m == INF)
            return point(this->b, o.m * this->b + o.b);
        if(o.m == INF)
            return point(o.b, this->m * o.b + this->b);
        double x = (o.b - this->b) / (this->m - o.m);
        return point(x, this->m * x + this->b);
    }
};

bool on_line_segment(point & a, point & b, point & c){
    return fabs(a.dist(b) - c.dist(a) - c.dist(b)) < EPS;
}

int n;
point p1[53], p2[53];
line l[53];

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        int ans = 0;
        for(int i = 0; i < n; i++)
            cin >> p1[i].x >> p1[i].y >> p2[i].x >> p2[i].y, l[i] = line(p1[i], p2[i]);
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                for(int k = j + 1; k < n; k++)
                    if(!l[i].parallel(l[j]) && !l[i].parallel(l[k]) && !l[j].parallel(l[k])){
                        point x = l[i].intersect(l[j]);
                        point y = l[i].intersect(l[k]);
                        point z = l[j].intersect(l[k]);
                        if(on_line_segment(p1[i], p2[i], x) && on_line_segment(p1[i], p2[i], y) &&
                            on_line_segment(p1[j], p2[j], x) && on_line_segment(p1[j], p2[j], z) &&
                            on_line_segment(p1[k], p2[k], y) && on_line_segment(p1[k], p2[k], z))
                                ans++;
                    }
        cout << ans << endl;
    }
}