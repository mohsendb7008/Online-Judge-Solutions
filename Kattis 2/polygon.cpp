#ifndef POINT2D
#include "point2D.cpp"
#endif

#include <vector>

template <typename T>
struct polygon {
    std::vector<point2D<T>> corners;
    // ReSharper disable once CppNonExplicitConvertingConstructor
    polygon(std::vector<point2D<T>> corners) : corners(corners) {}

    T SignedDoubledArea() {
        const size_t n = corners.size();
        T sum = 0;
        for (size_t i = 0; i < n; i++) {
            sum += corners[i].cross(corners[(i + 1) % n]);
        }
        return sum;
    }

    T DoubledArea() {
        return fabs(SignedDoubledArea());
    }

    T SignedArea() {
        return SignedDoubledArea() / 2.0;
    }

    T Area() {
        return DoubledArea() / 2.0;
    }

    bool onSegment(point2D<T> a, point2D<T> b, point2D<T> p) {
        if (fabs((b - a).cross(p - a)) > EPS)
            return false;
        return (p - a).dot(p - b) <= 0;
    }

    PointStatus status(const point2D<T> &p) {
        const size_t n = corners.size();
        for (size_t i = 0; i < n; i++) {
            if (onSegment(corners[i], corners[(i + 1) % n], p))
                return ON;
        }
        double a = 0;
        for (size_t i = 0; i < n; i++) {
            point2D<T> s = corners[i] - p;
            point2D<T> d = corners[(i + 1) % n] - p;
            a += s.angle(d);
        }
        if (fabs(a) < EPS)
            return OUT;
        return IN;
    }
};