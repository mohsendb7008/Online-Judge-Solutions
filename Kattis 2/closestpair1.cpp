#include "closestPair.cpp"
#include "iostream"
#include "iomanip"

using namespace std;

vector<point2D<double>> points;

int main() {
    cout << fixed << setprecision(2);
    while (true) {
        int n;
        cin >> n;
        if (!n)
            break;
        points.clear();
        while (n--) {
            double x, y;
            cin >> x >> y;
            points.emplace_back(x, y);
        }
        closestPair closest = points;
        const closestPairResult result = closest.find();
        cout << result.p1.x << " " << result.p1.y << " " << result.p2.x << " " << result.p2.y << endl;
    }
}