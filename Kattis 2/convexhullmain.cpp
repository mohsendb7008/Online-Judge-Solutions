#include "convexHull.cpp"
#include "iostream"

using namespace std;

vector<point2D<int>> points;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (!n)
            break;
        points.clear();
        while (n--) {
            int x, y;
            cin >> x >> y;
            points.emplace_back(x, y);
        }
        points = ConvexHull<int>::get(points);
        cout << points.size() << endl;
        for (const point2D<int> p : points) {
            cout << p.x << " " << p.y << endl;
        }
    }
}