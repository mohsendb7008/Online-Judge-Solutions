#ifndef POINT2D
#include "point2D.cpp"
#endif

#include <vector>
#include <algorithm>

static bool equals(const point2D<double> &a, const point2D<double> &b) {
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}

struct lineSegment {
    point2D<double> a, b;

    lineSegment(const point2D<double> a, const point2D<double> b) : a(a), b(b) {
    }

    bool isPoint() const {
        return equals(a, b);
    }

    bool hasPoint(const point2D<double> &point) const {
        const point2D<double> d = b - a;
        const point2D<double> p = point - a;
        if (fabs(d.cross(p)) > EPS)
            return false;
        const double t = p.dot(d) / d.dot(d);
        return t >= -EPS && t <= 1 + EPS;
    }

    double distance(const point2D<double> &point) const {
        const point2D<double> dp = b - a;
        if ((point - a).dot(dp) >= -EPS && (point - b).dot(dp) <= EPS) {
            return fabs((point - a).cross(dp)) / a.distance(b);
        }
        return std::min(point.distance(a), point.distance(b));
    }

    std::vector<point2D<double> > intersect(const lineSegment &o) const {
        std::vector<point2D<double> > result;

        const bool A = isPoint();
        const bool B = o.isPoint();
        if (A && B) {
            if (equals(a, o.a))
                result.push_back(a);
            return result;
        }
        if (A) {
            if (o.hasPoint(a))
                result.push_back(a);
            return result;
        }
        if (B) {
            if (hasPoint(o.a))
                result.push_back(o.a);
            return result;
        }

        const point2D<double> p = a, q = o.a, dp = b - a, dq = o.b - o.a;
        const double PxQ = dp.cross(dq);

        if (fabs(PxQ) < EPS) {
            if (fabs((q - p).cross(dp)) > EPS)
                return result;

            double alpha = (q - p).dot(dp) / dp.dot(dp);
            double beta = (o.b - p).dot(dp) / dp.dot(dp);
            if (alpha > beta)
                std::swap(alpha, beta);

            const double s = std::max(0.0, alpha);
            const double t = std::min(1.0, beta);
            if (s > t + EPS)
                return result;

            point2D<double> p1 = p + dp * s;
            point2D<double> p2 = p + dp * t;

            if (equals(p1, p2))
                result.push_back(p1);
            else {
                if (p2.x < p1.x || (fabs(p1.x - p2.x) < EPS && p2.y < p1.y))
                    std::swap(p1, p2);
                result.push_back(p1);
                result.push_back(p2);
            }
            return result;
        }

        const double s = (q - p).cross(dq) / PxQ;
        const double t = (q - p).cross(dp) / PxQ;
        if (s >= -EPS && s <= 1 + EPS && t >= -EPS && t <= 1 + EPS)
            result.push_back(p + dp * s);
        return result;
    }

    double distance(const lineSegment &o) const {
        const bool A = isPoint();
        const bool B = o.isPoint();
        if (A && B) {
            return a.distance(o.a);
        }
        if (A) {
            return o.distance(a);
        }
        if (B) {
            return distance(o.a);
        }

        if (intersect(o).empty()) {
            return std::min(distance(o.a),
                            std::min(distance(o.b),
                                     std::min(o.distance(a), o.distance(b)))
            );
        }
        return 0;
    }
};
