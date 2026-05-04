#include "polygon.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

point2D<double> intersect(const point2D<double> A, const point2D<double> B, const point2D<double> p, const point2D<double> n) {
    const point2D<double> AB = B - A;
    const double t = (p - A).dot(n) / AB.dot(n);
    return A + AB * t;
}

polygon<double> clip(const polygon<double>& poly, const point2D<double> p, const point2D<double> n, const bool sign) {
    vector<point2D<double>> res;
    for (int i = 0; i < poly.corners.size(); i++) {
        point2D<double> A = poly.corners[i];
        point2D<double> B = poly.corners[(i + 1) % poly.corners.size()];
        double da = (A - p).dot(n);
        double db = (B - p).dot(n);
        if (!sign) {
            da = -da;
            db = -db;
        }
        const bool ina = da >= -EPS;
        const bool inb = db >= -EPS;
        if (ina) {
            res.push_back(A);
        }
        if (ina != inb) {
            res.push_back(intersect(A, B, p, n));
        }
    }
    return res;
}

int main() {
    cout << fixed << setprecision(6);
    const vector<point2D<double>> initial = {
        {0,0}, {10,0}, {10,10}, {0,10}
    };
    polygon<double> poly = initial;
    point2D<double> prev = {0,0};
    double x, y;
    string s;
    while (cin >> x >> y >> s) {
        point2D<double> cur = {x, y};
        if (!poly.corners.empty()) {
            const point2D<double> mid = (prev + cur) / 2.0;
            const point2D<double> normal = cur - prev;
            if (s == "Hotter") {
                poly = clip(poly, mid, normal, true);
            } else if (s == "Colder") {
                poly = clip(poly, mid, normal, false);
            } else {
                poly.corners.clear();
            }
        }
        cout << poly.Area() << endl;
        prev = cur;
    }
}