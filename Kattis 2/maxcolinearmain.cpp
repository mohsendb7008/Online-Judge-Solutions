#include "maxColinear.cpp"
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
        cout << maxColinear<int>::get(points).size() << endl;
    }
}