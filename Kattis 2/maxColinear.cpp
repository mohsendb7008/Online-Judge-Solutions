#include "point2D.cpp"
#include "fraction.cpp"
#include <vector>
#include <map>

template <typename T>
struct maxColinear {
    static std::vector<point2D<T>> get(const std::vector<point2D<T>>& points) {
        if (points.size() < 2)
            return points;
        size_t best = 0;
        std::vector<point2D<T>> result;
        for (point2D<T> fixed : points) {
            std::map<fraction<T>, std::vector<point2D<T>>> colinear;
            for (point2D<T> relative : points) {
                if (relative == fixed)
                    continue;
                fraction<T> slope(relative.y - fixed.y, relative.x - fixed.x);
                colinear[slope].push_back(relative);
            }
            for (auto it : colinear) {
                if (it.second.size() > best) {
                    best = it.second.size();
                    result = it.second;
                    result.push_back(fixed);
                }
            }
        }
        return result;
    }
};