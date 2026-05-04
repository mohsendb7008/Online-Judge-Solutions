#include "lineSegment.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << setprecision(2);
    int tc;
    cin >> tc;
    while (tc--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        lineSegment l1({x1, y1}, {x2, y2}), l2({x3, y3}, {x4, y4});
        cout << l1.distance(l2) << endl;
    }
}
