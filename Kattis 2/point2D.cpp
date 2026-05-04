#define POINT2D
#include <cmath>

constexpr double EPS = 1e-9;

template <typename T>
struct point2D {
    T x, y;
    point2D(T x, T y) : x(x), y(y) {}

    bool operator== (const point2D &o) const {
        return fabs(x - o.x) < EPS && fabs(y - o.y) < EPS;
    }

    point2D operator+ (const point2D &o) const {
        return point2D(x + o.x, y + o.y);
    }

    point2D operator- (const point2D &o) const {
        return point2D(x - o.x, y - o.y);
    }

    point2D operator* (T s) const {
        return point2D(x * s, y * s);
    }

    point2D operator/ (T s) const {
        return point2D(x / s, y / s);
    }

    T dot(const point2D &o) const {
        return x * o.x + y * o.y;
    }

    T cross(const point2D &o) const {
        return x * o.y - o.x * y;
    }

    double distance(const point2D &o) const {
        point2D d = *this - o;
        return hypot(d.x, d.y);
    }

    double angle(const point2D &o) const {
        return atan2(cross(o), dot(o));
    }
};

enum PointStatus {
    IN, ON, OUT
};