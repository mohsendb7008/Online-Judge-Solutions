#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

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

struct circle{
    point center;
    double radius;

    circle(point c, double r){
        center = c;
        radius = r;
    }

    int status(point& p){
        double dx = p.x - center.x, dy = p.y - center.y;
        double euc = dx * dx + dy * dy;
        if(fabs(euc - radius * radius) < EPS)
            return 0; // on circle
        if(euc < radius * radius)
            return -1; // inside circle
        return 1; // outside circle
    }
};

pair<circle, circle> circles_with_2_points(point& p1, point& p2, double r){
    double l = p1.dist(p2);
    double a = sqrt(r * r - l * l / 4);
    return {circle(point((p1.x + p2.x) / 2 + (p1.y - p2.y) * a / l, (p1.y + p2.y) / 2 + (p2.x - p1.x) * a / l), r),
            circle(point((p1.x + p2.x) / 2 + (p2.y - p1.y) * a / l, (p1.y + p2.y) / 2 + (p1.x - p2.x) * a / l), r)};
}

int n, m;
double r;
point mosquitoes[32 + 3];

int main(){
    cin >> m;
    while(m--){
        cin >> n >> r, r /= 2;
        for(int i = 0; i < n; i++)
            cin >> mosquitoes[i].x >> mosquitoes[i].y;
        int ans = 1;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(mosquitoes[i].dist(mosquitoes[j]) < 2 * r + EPS){
                    pair<circle, circle> pc = circles_with_2_points(mosquitoes[i], mosquitoes[j], r);
                    int ans1 = 0, ans2 = 0;
                    for(int k = 0; k < n; k++){
                        if(pc.first.status(mosquitoes[k]) != 1)
                            ans1++;
                        if(pc.second.status(mosquitoes[k]) != 1)
                            ans2++;
                    }
                    ans = max(ans, max(ans1, ans2));
                }
        cout << ans << endl; 
    }
}

