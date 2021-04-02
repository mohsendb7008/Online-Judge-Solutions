#include <bits/stdc++.h>
using namespace std;

// Completing the Square

struct point{
    int x, y;
    
    point(){
        x = 0, y = 0;
    }
    
    point(int x, int y){
        this->x = x, this->y = y;
    }
    
    double dist(const point& o){
        int dx = x - o.x, dy = y - o.y;
        return dx * dx + dy * dy;
    }
};

struct vec{
    int x, y;
    
    vec(int x, int y){
        this->x = x;
        this->y = y;
    }

    vec(point & p1, point & p2){
        this->x = p2.x - p1.x;
        this->y = p2.y - p1.y;
    }

    point translate(point & p){
        return point(p.x + this->x, p.y + this->y);
    }

    vec operator+(const vec& o) const{
        return vec(this->x + o.x, this->y + o.y);
    }
};

point a[3];

int main(){
    for(int i = 0; i < 3; i++)
        cin >> a[i].x >> a[i].y;
    if(a[0].dist(a[1]) != a[0].dist(a[2])){
        if(a[1].dist(a[0]) == a[1].dist(a[2]))
            swap(a[1], a[0]);
        else
            swap(a[2], a[0]);
    }
    vec v1(a[0], a[1]), v2(a[0], a[2]);
    vec v3 = v1 + v2;
    point ans = v3.translate(a[0]);
    cout << ans.x << " " << ans.y << endl;
}