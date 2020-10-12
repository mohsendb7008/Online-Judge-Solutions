#include <bits/stdc++.h>
using namespace std;

// Finding Lines

#define num long long int

struct point{
    num x, y;
    
    point() = default;
    
    point(num x, num y){
        this->x = x, this->y = y;
    }
	
	point& operator=(const point& o) = default; 
};

struct vec{
    num x, y;
    
	vec() = default;
	
    vec(num x, num y){
        this->x = x;
        this->y = y;
    }

    vec(point& p1, point& p2){
        this->x = p2.x - p1.x;
        this->y = p2.y - p1.y;
    }

    vec& operator=(const vec& o) = default; 

    num cross(vec& o){
        return this->x * o.y - this->y * o.x;
    }
};

bool collinear(point& p, point& q, point& r){
    vec v(p, r);
    return vec(p, q).cross(v) == 0;
}

const int maxn = 1e5 + 3;

int n, p;
point points[maxn];

int main(){
    srand(time(0));
    cin >> n >> p, p = (n * p) / 100 + (((n * p) % 100) ? 1 : 0);
    for(int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    if(p == 1){
        cout << "possible" << endl;
        return 0;
    }
    for(int _ = 0; _ < 1000; _++){
        int i = rand() % n, j = rand() % n;
        if(i == j)
            continue;
        int ans = 2;
        for(int k = 0; k < n; k++)
            if(k != i && k != j)
                ans += collinear(points[i], points[j], points[k]);
        if(ans >= p){
            cout << "possible" << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
}