#include<bits/stdc++.h>
using namespace std;

// Cleaning Pipes

struct point{
    int x, y;
    
    point() = default;
    
    point(int x, int y){
        this->x = x, this->y = y;
    }
	
	point& operator=(const point& o) = default; 

    bool operator==(const point& o) const{
        return this->x == o.x && this->y == o.y;
    }
};

struct vec{
    int x, y;
    
	vec() = default;
	
    vec(int x, int y){
        this->x = x;
        this->y = y;
    }

    vec(point& p1, point& p2){
        this->x = p2.x - p1.x;
        this->y = p2.y - p1.y;
    }

    vec& operator=(const vec& o) = default; 

    int cross(vec& o){
        return this->x * o.y - this->y * o.x;
    }
};

int ccw(point& p, point& q, point& r){
    vec v(p, r);
    int c = vec(p, q).cross(v);
    if(c > 0)
        return 1;
    else if(!c)
        return 0;
    return -1;
}

// Checking if two line segments p1p2 and q1q2 intersects with assumption that p1 != q1 (wells are not same): 
bool intersect(point& p1, point& p2, point& q1, point& q2){
    int a = ccw(p1, p2, q1), b = ccw(p1, p2, q2);
    if(a * b > 0)
        return false;
    else if(!a && !b && !(p2 == q2))
        return false;
    a = ccw(q1, q2, p1), b = ccw(q1, q2, p2);
    if(a * b > 0)
        return false;
    else if(!a && !b && !(q2 == p2))
        return false;
    return true;
}

int w, p, pipe[1003], color[1003];
point well[1003], endp[1003];
vector<int> adj[1003];
bool bicolorable = true;

void dfs(int u, int c){
    color[u] = c;
    for(int v : adj[u]){
        if(color[v] == c)
            bicolorable = false;
        if(color[v] == 2)
            dfs(v, 1 - c);
    }
}

int main(){
    cin >> w >> p;
    for(int i = 0; i < w; i++)
        cin >> well[i].x >> well[i].y;
    for(int i = 0; i < p; i++)
        cin >> pipe[i] >> endp[i].x >> endp[i].y, pipe[i]--;
    for(int i = 0; i < p; i++)
        for(int j = i + 1; j < p; j++)
            if(pipe[i] != pipe[j] && intersect(well[pipe[i]], endp[i], well[pipe[j]], endp[j]))
                adj[i].push_back(j), adj[j].push_back(i);
    fill_n(color, p, 2);
    for(int i = 0; i < p; i++)
        if(color[i] == 2)
            dfs(i, 0);
    cout << (bicolorable ? "possible" : "impossible") << endl;
}