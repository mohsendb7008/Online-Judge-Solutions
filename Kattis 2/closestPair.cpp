#include "point2D.cpp"
#include <vector>
#include <algorithm>

static bool byX(const point2D<double> &p1, const point2D<double> &p2) {
    return p1.x < p2.x;
}

static bool byY(const point2D<double> &p1, const point2D<double> &p2) {
    return p1.y < p2.y;
}

struct closestPairResult {
    double dis;
    point2D<double> p1, p2;

    closestPairResult() : dis(0.0), p1(0.0, 0.0), p2(0.0, 0.0) {
    }
};

struct closestPair {
    std::vector<point2D<double> > points, tmp;
    // ReSharper disable once CppNonExplicitConvertingConstructor
    closestPair(const std::vector<point2D<double> > &points) : points(points) {
        std::sort(this->points.begin(), this->points.end(), byX);
        tmp.assign(points.size(), {0.0, 0.0});
    }

    closestPairResult find(const size_t l, const size_t r) {
        closestPairResult ans;
        if (r - l == 1) {
            ans.dis = points[l].distance(points[r]);
            ans.p1 = points[l];
            ans.p2 = points[r];
        } else if (r - l == 2) {
            ans.dis = points[r - 1].distance(points[r]);
            ans.p1 = points[r - 1];
            ans.p2 = points[r];
            for (size_t k = r - 1; k <= r; k++) {
                const double dis = points[l].distance(points[k]);
                if (dis < ans.dis) {
                    ans.dis = dis;
                    ans.p1 = points[l];
                    ans.p2 = points[k];
                }
            }
        } else {
            const size_t mid = (l + r) / 2;
            const closestPairResult left = find(l, mid);
            const closestPairResult right = find(mid + 1, r);
            if (left.dis < right.dis) {
                ans.dis = left.dis;
                ans.p1 = left.p1;
                ans.p2 = left.p2;
            } else {
                ans.dis = right.dis;
                ans.p1 = right.p1;
                ans.p2 = right.p2;
            }
            const auto lPtr = std::lower_bound(points.begin() + l, points.begin() + r + 1,
                                               point2D<double>(points[mid].x - ans.dis, 0.0), byX);
            const auto rPtr = std::upper_bound(points.begin() + l, points.begin() + r + 1,
                                               point2D<double>(points[mid + 1].x + ans.dis, 0.0), byX);
            const size_t size = rPtr - lPtr;
            copy(lPtr, rPtr, tmp.begin());
            sort(tmp.begin(), tmp.begin() + size, byY);
            for (size_t i = 0; i < size; i++)
                for (size_t j = i + 1; j < std::min(i + 16, size); j++) {
                    const double dis = tmp[i].distance(tmp[j]);
                    if (dis < ans.dis) {
                        ans.dis = dis;
                        ans.p1 = tmp[i];
                        ans.p2 = tmp[j];
                    }
                }
        }
        return ans;
    }

    closestPairResult find() {
        return find(0, static_cast<int>(points.size()) - 1);
    }
};
