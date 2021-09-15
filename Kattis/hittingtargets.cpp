#include <bits/stdc++.h>
using namespace std;

// Hitting the Targets

class Shape {
public:
    virtual bool is_inside(int x, int y) const = 0;
};

class Rectangle: public Shape {
    int x1, x2, y1, y2;
public:
    Rectangle(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {}
    bool is_inside(int x, int y) const override {
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;
    }
};

class Circle: public Shape {
    pair<int, int> c;
    int r;
public:
    Circle(int x, int y, int r) : c({x, y}), r(r) {}
    bool is_inside(int x, int y) const override {
        return hypot(c.first - x, c.second - y) < r + 1e-9;
    }
};

vector<Shape*> shapes;
int x, y;

int main(){
    int m;
    cin >> m;
    while(m--){
        string type;
        cin >> type;
        if(type == "rectangle"){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            shapes.push_back(new Rectangle(x1, x2, y1, y2));
        }
        else if(type == "circle"){
            int x, y, r;
            cin >> x >> y >> r;
            shapes.push_back(new Circle(x, y, r));
        }
    }
    int n;
    cin >> n;
    while(n--){
        cin >> x >> y;
        cout << count_if(shapes.begin(), shapes.end(), [](const Shape* shape){return shape->is_inside(x, y);}) << endl;
    }    
}