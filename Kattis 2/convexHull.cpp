#ifndef POINT2D
#include "point2D.cpp"
#endif

#include <vector>
#include <algorithm>

template<typename T>
struct ConvexHull {
    static int orientation(const point2D<T> &a,
                           const point2D<T> &b,
                           const point2D<T> &c) {
        T v = (b - a).cross(c - a);
        if (v >= EPS)
            return 1;
        if (v <= -EPS)
            return -1;
        return 0;
    }

    static bool byXY(const point2D<T> &a, const point2D<T> &b) {
        if (fabs(a.x - b.x) >= EPS)
            return a.x < b.x;
        return a.y < b.y;
    }

    static bool byAngle(const point2D<T> &a,
                        const point2D<T> &b,
                        const point2D<T> &p0) {
        T cr = (a - p0).cross(b - p0);
        if (fabs(cr) < EPS) {
            return p0.distance(a) < p0.distance(b);
        }
        return cr >= EPS;
    }

    static std::vector<point2D<T>> get(std::vector<point2D<T>> points) {
        std::sort(points.begin(), points.end(), byXY);
        points.erase(std::unique(points.begin(), points.end()), points.end());
        if (points.size() <= 1)
            return points;

        std::vector<point2D<T>> hull;
        int idx = 0;
        for (int i = 1; i < points.size(); i++) {
            if (byXY(points[i], points[idx]))
                idx = i;
        }
        std::swap(points[0], points[idx]);
        point2D<T> p0 = points[0];
        std::sort(points.begin() + 1, points.end(),
            [&](const point2D<T> &a, const point2D<T> &b) {
                return byAngle(a, b, p0);
            });

        hull.push_back(p0);
        for (int i = 1; i < points.size(); i++) {
            while (hull.size() >= 2 &&
                   orientation(hull[hull.size() - 2],
                               hull.back(),
                               points[i]) <= 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }

        bool allCollinear = true;
        for (int i = 2; i < points.size(); i++) {
            if (orientation(points[0], points[1], points[i]) != 0) {
                allCollinear = false;
                break;
            }
        }
        if (allCollinear) {
            std::sort(points.begin(), points.end(), byXY);
            hull.clear();
            hull.push_back(points.front());
            hull.push_back(points.back());
        }
        return hull;
    }
};