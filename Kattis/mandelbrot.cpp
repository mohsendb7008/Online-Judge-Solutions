#include <bits/stdc++.h>
using namespace std;

// Mandelbrot

#define EPS 1e-9

struct point{
    double x, y;
    
    point(){
        x = 0, y = 0;
    }
    
    point(double x, double y){
        this->x = x, this->y = y;
    }
    
    double norm(){
        return hypot(x, y);
    }
    
    point pow2(){
        return point(x * x - y * y, 2 * x * y);
    }

    point operator+(const point& o) const{
        return point(x + o.x, y + o.y);
    }
};

int r;
point c;

int main(){
    int t = 1;
    while(cin >> c.x >> c.y >> r){
        point z;
        bool in = true;
        while(r--){
            z = z.pow2() + c;
            if(z.norm() > 2.0 - EPS){
                in = false;
                break;
            }
        }
        cout << "Case " << t++ << ": " << (in ? "IN" : "OUT") << endl;
    }
}